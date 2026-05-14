// =============================================================================
// FUN_140089510 @ 0x140089510 -- proposed name: crispr_lab_state_machine
//
// PURPOSE:
//   The CRISPR Lab state machine. Manages the player's interactions inside the
//   gene-editing lab: vial zoom-in/out animation, chromosome scanning, genome
//   clipboard copy/paste, and the actual gene-edit application.
//
// CALLED BY: per-frame update from the location dispatcher when the player is
//   in the CRISPR Lab.
// SIZE: 8,654 bytes.
//
// STATE FIELDS (on param_1, the CRISPR sub-state struct):
//   param_1 + 0x148 -- player's active horse pointer (the one being edited)
//   param_1 + 0x250 -- current STATE id (uint32)
//   param_1 + 0x254 -- frame counter within state (uint32; resets on transition)
//   param_1 + 0x270 -- "current chromosome" pointer (set during vial)
//   param_1 + 0x278 -- some output / temp pointer
//   param_1 + 0x280 -- pending-transition flag
//   param_1 + 0x284 -- frame budget for current animation (e.g. 0x78 = 120 = ~2s)
//
// STATES OBSERVED:
//   0   -- idle
//   7   -- Extraction in progress (plays "Extraction complete" string near end)
//   9   -- ComputerCopy ... at frame 30 prints "Genome copied to clipboard!"
//          and advances to state 2.
//   10  -- (some related copy/paste branch)
//   11 (0xb)  -- VialZoomIn animation; at frame 1 plays "VialZoomIn" sound and
//                calls FUN_1400fce70 (enter vial). At frame 0x79 (121) advances
//                to state 12 (sub-map "VialWorld").
//   12 (0xc)  -- INSIDE the vial sub-map ("VialWorld"). Player drives around
//                the purple chemical tiles. Leaving via a non-purple tile sets
//                state to 0xd.
//   13 (0xd)  -- VialZoomOut animation; at frame 1 plays "VialZoomOut" sound,
//                calls FUN_1400fd1e0 (exit vial). At frame 0x79 calls
//                FUN_1400fd3e0 (scan_for_chromosomes) and returns to state 2.
//
// STRINGS REFERENCED:
//   "Extraction complete"
//   "ComputerCopy"           (sound)
//   "Genome copied to clipboard!"
//   "Pasting genome from clipboard!"
//   "VialZoomIn", "VialZoomOut" (sounds)
//   "VialWorld"              (sub-map name)
//   "SAMPLING DNA..."
//   "Found %d/%d chromosomes"
//
// CRISPR MECHANIC SUMMARY:
//   1. Player enters Lab => state transitions to 0xb (VialZoomIn).
//   2. Zoom completes => state 0xc, player is in VialWorld with Cas9 + chromos.
//   3. Player drives off the vial island => state 0xd (VialZoomOut).
//   4. At zoom-out end, FUN_1400fd3e0 scans the player's collected chromosomes
//      and applies them to the horse at +0x148.
//   5. Genome copy/paste (states 9/10): use clipboard text as a portable genome.
//
// HORSEY MOD IMPLICATION:
//   - Clipboard genome paste is a way to GIVE a horse arbitrary genes by
//     hand-crafting the text format. The serialization function is called from
//     this state machine; finding it gives us the genome text format.
//   - The scan in state 13 is what writes new genes onto the horse. Replacing
//     the source genome (e.g. paste-mode) bypasses the manual chromosome-hunt.
// =============================================================================

void crispr_lab_state_machine(longlong param_1)
{
  // Dispatch on current state.
  switch (*(int *)(param_1 + 0x250)) {

  case 7: /* extraction state */ {
    if (frame == END_OF_EXTRACTION) {
      show_message("Extraction complete");
      // Call FUN_1400d0c80 which displays the message via the dialog handler.
    } else {
      *(undefined8 *)(param_1 + 0x278) = 0;
    }
    break;
  }

  case 9: /* genome clipboard COPY */ {
    if (frame == 1) {
      play_sound("ComputerCopy");
    }
    if (frame == 30) {
      // Build "Genome copied to clipboard!" UTF-8 string in a malloc'd buffer.
      char *buf = (char *)FUN_1400285e0(0x20);   // alloc 32 bytes
      // ... copy literal bytes from s_Genome_copied_to_clipboard__14030b560 ...
      show_message(buf);
      *(undefined8 *)(param_1 + 0x250) = 2;  // advance state
    }
    break;
  }

  case 10: /* genome clipboard PASTE handling, similar pattern */
    break;

  case 11 /* 0xb */: /* VialZoomIn */ {
    if (frame == 1) {
      play_sound("VialZoomIn");
      FUN_1400fce70(game_state, current_chromosome);   // begin vial transition
      *(uint*)(param_1 + 0x280) = 1;
      *(uint*)(param_1 + 0x284) = 0x78;                // ~2 second animation budget
    } else if (frame == 0x79 /* 121 */) {
      *(uint*)(param_1 + 0x250) = 0xc;                 // enter VialWorld
      // ... load VialWorld map ...
    }
    break;
  }

  case 12 /* 0xc */: /* in VialWorld */ {
    // Movement / cas9 collection is handled by general world-update code.
    // This case mostly waits for a non-purple-chemical tile to be touched.
    break;
  }

  case 13 /* 0xd */: /* VialZoomOut */ {
    if (frame == 1) {
      play_sound("VialZoomOut");
      FUN_1400fd1e0(game_state);
      *(uint*)(param_1 + 0x280) = 1;
      *(uint*)(param_1 + 0x284) = 0x78;
    } else if (frame == 0x79) {
      if (*(longlong*)(param_1 + 0x270) != 0) {
        // Apply collected chromosomes to horse->genome.
        FUN_1400fd3e0(game_state, current_chromosome->thing);
      }
      *(uint*)(param_1 + 0x250) = 2;
    }
    break;
  }
  }
}
