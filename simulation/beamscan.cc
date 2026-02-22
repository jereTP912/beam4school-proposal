//
// BeamScan: BL4S 2026 — Material classification via MCS and energy loss
// Main application
//

#include "DetectorConstruction.hh"
#include "ActionInitialization.hh"

#include "G4RunManagerFactory.hh"
#include "G4UImanager.hh"
#include "G4VisExecutive.hh"
#include "G4UIExecutive.hh"
#include "FTFP_BERT.hh"
#include "G4EmStandardPhysics_option4.hh"
#include "G4PhysListFactory.hh"
#include "G4StepLimiterPhysics.hh"

int main(int argc, char** argv)
{
    // Detect interactive mode
    G4UIExecutive* ui = nullptr;
    if (argc == 1) {
        ui = new G4UIExecutive(argc, argv);
    }

    // Construct the run manager in serial mode.
    // Serial produces a single clean CSV per simulation, avoiding the
    // per-thread file splitting of MT mode (which complicates analysis).
    // For our event counts (2000–10000) serial is fast enough.
    auto runManager = G4RunManagerFactory::CreateRunManager(
        G4RunManagerType::Serial);

    // Physics list: FTFP_BERT with high-precision EM (option4 for accurate MCS)
    auto physicsList = new FTFP_BERT;
    physicsList->ReplacePhysics(new G4EmStandardPhysics_option4());
    physicsList->RegisterPhysics(new G4StepLimiterPhysics());
    runManager->SetUserInitialization(physicsList);

    // Detector geometry
    auto detConstruction = new DetectorConstruction();
    runManager->SetUserInitialization(detConstruction);

    // User actions (MT-compatible via ActionInitialization)
    runManager->SetUserInitialization(new ActionInitialization());

    // Visualization
    auto visManager = new G4VisExecutive;
    visManager->Initialize();

    auto UImanager = G4UImanager::GetUIpointer();

    if (!ui) {
        // Batch mode — run macro from command line
        // Support both:
        //   ./beamscan mymacro.mac
        // and (student-friendly):
        //   ./beamscan -m mymacro.mac
        G4String fileName;
        if (argc == 3 && G4String(argv[1]) == "-m") {
            fileName = argv[2];
        } else {
            fileName = argv[1];
        }

        G4String command = "/control/execute ";
        UImanager->ApplyCommand(command + fileName);
    } else {
        // Interactive mode
        UImanager->ApplyCommand("/control/execute macros/init_vis.mac");
        ui->SessionStart();
        delete ui;
    }

    delete visManager;
    delete runManager;
    return 0;
}
