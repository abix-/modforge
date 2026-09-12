# Character health, stats, and input

[Research index](abiotic-factor.md) | [Todo](todo.md)

## body part health

Separate tracking per limb:
- Head, Torso, LeftArm, RightArm, LeftLeg, RightLeg
- `MaxHealthModifier`, `MaxHeadHealthModifier`, `MaxTorsoHealthModifier`
- `DefaultMax_LimbHealthMap` for per-limb max health

## character stats

- `BaseWalkSpeed`, `BaseSprintSpeed`, `MinimumMovementSpeed`
- `GlobalSpeedModifier`, `GlobalSprintSpeedModifier`
- `GlobalSwimSpeedModifier`, `GlobalCrouchSpeedModifier`
- `CurrentStamina`, `MaxStamina`, `StaminaRequiredToSprint`
- Jetpack support (JetpackTimestamp)
- Ghost mode (GhostModeAIDebugState)

## player input (read from the shipped PDB, 2026-09-12)

The game does not use Enhanced Input for gameplay: with a save loaded,
0 InputMappingContext and 0 InputAction assets exist; the only hits are
6 legacy `InputActionDelegateBinding` objects (Blueprint input events).
Player input therefore goes through the legacy `PlayerInput` path and its
native `InputKey`, which is not a UFunction. The addresses and layouts
below come from `AbioticFactor-Win64-Shipping.pdb` through
`ueforge::symbols` (`tests/research_symbols.rs`), not from guessing.

| Function | Image-relative address | Decorated name |
|---|---|---|
| `APlayerController::InputKey(const FInputKeyParams&)` | `0x3AB2890` | `?InputKey@APlayerController@@UEAA_NAEBUFInputKeyParams@@@Z` |
| `APlayerController::InputKey(FKey, EInputEvent, float, bool)` | `0x3AB2BB0` | `?InputKey@APlayerController@@UEAA_NUFKey@@W4EInputEvent@@M_N@Z` |
| `UPlayerInput::InputKey(const FInputKeyParams&)` | `0x3DA2190` | `?InputKey@UPlayerInput@@UEAA_NAEBUFInputKeyParams@@@Z` |
| `UPlayerInput::InputKey(FKey, EInputEvent, float, bool)` | `0x3DA28F0` | `?InputKey@UPlayerInput@@UEAA_NUFKey@@W4EInputEvent@@M_N@Z` |
| `UGameViewportClient::InputKey(const FInputKeyEventArgs&)` | `0x3716C80` | `?InputKey@UGameViewportClient@@UEAA_NAEBUFInputKeyEventArgs@@@Z` |

`FInputKeyParams` is 72 bytes (UE 5.4, so the same layout applies to
MISERY; the earlier 64-byte guess in the workspace todo was wrong):

| Offset | Size | Field | Type |
|---:|---:|---|---|
| 0 | 24 | Key | FKey |
| 24 | 4 | InputDevice | FInputDeviceId |
| 28 | 4 | Event | EInputEvent |
| 32 | 4 | NumSamples | int32 |
| 36 | 4 | DeltaTime | float |
| 40 | 24 | Delta | TVector<double> |
| 64 | 8 | bIsGamepadOverride | bool (padded) |

`FKey` is 24 bytes: `KeyName` FName at 0, `KeyDetails` TSharedPtr at 8.
`FInputKeyEventArgs` is 56 bytes: Viewport pointer at 0, ControllerId
int32 at 8, InputDevice at 12, Key at 16, Event at 40, AmountDepressed
float at 44, bIsTouchEvent at 48.
