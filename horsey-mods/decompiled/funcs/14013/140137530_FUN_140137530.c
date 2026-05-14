// Address: 0x140137530
// Ghidra name: FUN_140137530
// ============ 0x140137530 FUN_140137530 (size=221) ============


void FUN_140137530(ulonglong param_1,uint param_2,undefined1 param_3,undefined8 param_4)



{

  ulonglong uVar1;

  

  uVar1 = param_1 & 0xffffffff;

  if ((param_2 & 1) != 0) {

    FUN_140175280(param_1,"SDL.gpu.device.create.shaders.private",1);

  }

  if ((param_2 & 2) != 0) {

    FUN_140175280(uVar1,"SDL.gpu.device.create.shaders.spirv",1);

  }

  if ((param_2 & 4) != 0) {

    FUN_140175280(uVar1,"SDL.gpu.device.create.shaders.dxbc",1);

  }

  if ((param_2 & 8) != 0) {

    FUN_140175280(uVar1,"SDL.gpu.device.create.shaders.dxil",1);

  }

  if ((param_2 & 0x10) != 0) {

    FUN_140175280(uVar1,"SDL.gpu.device.create.shaders.msl",1);

  }

  if ((param_2 & 0x20) != 0) {

    FUN_140175280(uVar1,"SDL.gpu.device.create.shaders.metallib",1);

  }

  FUN_140175280(uVar1,"SDL.gpu.device.create.debugmode",param_3);

  FUN_140175500(uVar1,"SDL.gpu.device.create.name",param_4);

  return;

}




