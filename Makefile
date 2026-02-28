# ═══════════════════════════════════════════════════════════════
# BeamScan — Build all PDFs from source Markdown
# ═══════════════════════════════════════════════════════════════
#
# Usage:
#   make          — build all PDFs
#   make proposal — build proposal PDF only
#   make slides   — build slide PDFs only
#   make clean    — remove generated PDFs
#
# Requirements:
#   - pandoc + xelatex (for proposal)
#   - @marp-team/marp-cli (for slides)
#
# Install:
#   brew install pandoc mactex-no-gui    # macOS
#   npm install -g @marp-team/marp-cli   # Marp
# ═══════════════════════════════════════════════════════════════

OUTDIR := docs/pdf

# Source files
PROPOSAL_SRC := BL4S_Proposal_v4.md
OVERVIEW_SRC := docs/slides/BeamScan-Overview.marp.md
TECHDEEP_SRC := docs/slides/BeamScan-TechDeep.marp.md

# Output files
PROPOSAL_PDF := $(OUTDIR)/BL4S_2026_BeamScan_v4.pdf
OVERVIEW_PDF := $(OUTDIR)/BeamScan-Overview.pdf
TECHDEEP_PDF := $(OUTDIR)/BeamScan-TechDeep.pdf

ALL_PDFS := $(PROPOSAL_PDF) $(OVERVIEW_PDF) $(TECHDEEP_PDF)

.PHONY: all proposal slides clean

all: $(ALL_PDFS)

proposal: $(PROPOSAL_PDF)

slides: $(OVERVIEW_PDF) $(TECHDEEP_PDF)

$(OUTDIR):
	mkdir -p $(OUTDIR)

$(PROPOSAL_PDF): $(PROPOSAL_SRC) | $(OUTDIR)
	pandoc $< -o $@ \
		--pdf-engine=xelatex \
		-V geometry:margin=2.5cm \
		-V fontsize=11pt \
		-V colorlinks=true \
		-V linkcolor=blue \
		-V urlcolor=blue \
		--metadata title="BeamScan — BL4S 2026 Proposal"

$(OVERVIEW_PDF): $(OVERVIEW_SRC) | $(OUTDIR)
	npx @marp-team/marp-cli $< --pdf --allow-local-files -o $@

$(TECHDEEP_PDF): $(TECHDEEP_SRC) | $(OUTDIR)
	npx @marp-team/marp-cli $< --pdf --allow-local-files -o $@

clean:
	rm -f $(ALL_PDFS)
