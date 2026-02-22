#include "ActionInitialization.hh"
#include "PrimaryGeneratorAction.hh"
#include "RunAction.hh"
#include "EventAction.hh"
#include "SteppingAction.hh"

void ActionInitialization::BuildForMaster() const
{
    // Master thread only needs the RunAction (for merging results)
    SetUserAction(new RunAction());
}

void ActionInitialization::Build() const
{
    // Each worker thread gets its own set of actions
    SetUserAction(new PrimaryGeneratorAction());
    SetUserAction(new RunAction());

    auto eventAction = new EventAction();
    SetUserAction(eventAction);
    SetUserAction(new SteppingAction(eventAction));
}
