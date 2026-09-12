# Character saves, disconnect, and persistence

[Research index](abiotic-factor.md) | [Todo](todo.md)

## save system

- UAbioticSave with version migration (OldVersion, NewVersion, ApplyVersionUpgrade)
- Save types: World, WorldBackup, Keybinds, Settings, UserSettings, Customization, Unlocks, UserSettingsBP, PlayerStats
- Per-player and per-level save maps
- Compression support (bHasBeenCompressed)

## Disconnect, persistence, and remaining acceptance

**Decoded save identity:** game-mode K2_PostLogin enters 5668, creates voice
state and updates session settings, then, outside the editor branch, sets
UniquePlayerID using GetSteamIDFromPlayerState (5921) and PlayerSaveID using
UAbioticFunctionLibrary::GetPlayerSaveID (6076). It marks both for replication.
The native save-ID helper is RVA 0x46A8970: it calls
FUniqueNetIdWrapper::ToString (0x1F03000) on PlayerState.UniqueId (+712), converts
the resulting wide string with imported `_wtoi64`, and formats it with `%lld`.
The permanent `save_key_converts_network_identity_to_decimal` test resolves the
import through `modforge::patterns::sleuth` and verifies this conversion.

**Observed identity defect:** HTTP reads of Sophia's PlayerSaveID confirm it
is nonempty and exactly numeric zero. The current synthetic EOSPlus string
does not produce a distinct numeric save key. Preserving the profile ID alone
therefore does not establish distinct game persistence. Another nonnumeric bot
ID can collide at the same save key. Keep this separate from the proven spawn
freeze. Do not change identity or abandon the existing save as an incidental
fix; distinct accepted identity plus preservation of Sophia's current progress
is an explicit todo item.

**Decoded load:** LoadPlayerSaveData rejects non-server/non-saveable contexts,
gets the game instance, calls GetPlayerSave(PlayerSaveID, false) at 536, checks
the result, casts to Abiotic_Character_Save, copies CharacterSaveData into
CurrentPlayerSaveData at 1105, and returns Success=true and SavedData. A missing
save and failed cast return false/default data through different branches.

**Decoded write:** SavePlayerData rejects PendingPlayerDeletion and
non-saveable contexts, validates/selects the character and save location,
collects character state, and populates the save struct. CompletedIntro is
populated from HasSetUpSkills (5411..5429). It obtains the save object using
PlayerSaveID (8262), updates it and calls AddPlayerSaveToQueue (8561).
Completion of this function is not proof that the asynchronous save queue
has flushed to disk. The queue's writer/completion and logout ordering remain
to be traced.

The client currently attempts a channel-zero close on a normal bounded session
return. Force-killing the executable bypasses that code. Graceful process-stop
handling and a duplicate-instance guard remain separate todo items.

Decoded native AAbioticPlayerController::PawnLeavingGame is RVA 0x46EB660.
It uses the gameplay character reference at +2144, falls back to the controller
pawn at +728 when necessary, invokes actor cleanup, and clears possession.
Controller SaveCharacter's graph reaches the character's MyPlayerState and
SavePlayerData (45942). **Open:** the complete logout-to-save caller chain,
close acknowledgment/retransmission contract, save completion, and the safe
reconnect boundary. A client process exiting is not proof of server logout.

Sophia's profile and journal are local durable state. The server's character
save is different state, owned by the game. Keeping the same profile file does
not establish that inventory, traits, appearance, or position were saved.

Required acceptance after implementing verified transitions: a fresh host,
one Sophia process, saved-character spawn with a progressing game tick, new
character creation, valid loading completion, appearance application, graceful
logout, and reconnect with the same game character and local memory. Each must
be recorded separately; a transport acknowledgment cannot stand in for it.
