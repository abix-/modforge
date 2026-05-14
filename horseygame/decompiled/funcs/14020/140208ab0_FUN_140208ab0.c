// Address: 0x140208ab0
// Ghidra name: FUN_140208ab0
// ============ 0x140208ab0 FUN_140208ab0 (size=185) ============


void FUN_140208ab0(longlong param_1,undefined8 param_2)



{

  undefined4 uVar1;

  uint uVar2;

  

  uVar1 = FUN_140158c10(param_2);

  uVar2 = (**(code **)(*(longlong *)(param_1 + 0x68) + 0x68))(param_1,param_2);

  FUN_140175280(uVar1,"SDL.joystick.cap.mono_led",(byte)uVar2 & 1);

  FUN_140175280(uVar1,"SDL.joystick.cap.rgb_led",

                CONCAT31((uint3)(uVar2 >> 9),(char)(uVar2 >> 1)) & 0xffffff01);

  FUN_140175280(uVar1,"SDL.joystick.cap.player_led",uVar2 >> 2 & 0xffffff01);

  FUN_140175280(uVar1,"SDL.joystick.cap.rumble",uVar2 >> 4 & 0xffffff01);

  FUN_140175280(uVar1,"SDL.joystick.cap.trigger_rumble",(byte)(uVar2 >> 5) & 1);

  return;

}




