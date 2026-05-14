// Address: 0x140263230
// Ghidra name: FUN_140263230
// ============ 0x140263230 FUN_140263230 (size=200) ============


void FUN_140263230(ulonglong param_1)



{

  char cVar1;

  char cVar2;

  char cVar3;

  ulonglong uVar4;

  

  uVar4 = param_1 & 0xffffffff;

  cVar1 = FUN_1401749e0(param_1,"SDL.renderer.create.gpu.shaders_spirv",0);

  if (cVar1 != '\0') {

    FUN_140175280(uVar4,"SDL.gpu.device.create.shaders.spirv",1);

  }

  cVar2 = FUN_1401749e0(uVar4,"SDL.renderer.create.gpu.shaders_dxil",0);

  if (cVar2 != '\0') {

    FUN_140175280(uVar4,"SDL.gpu.device.create.shaders.dxil",1);

  }

  cVar3 = FUN_1401749e0(uVar4,"SDL.renderer.create.gpu.shaders_msl",0);

  if (cVar3 == '\0') {

    if (cVar2 != '\0' || cVar1 != '\0') {

      return;

    }

    FUN_140175280(uVar4,"SDL.gpu.device.create.shaders.private",0);

    FUN_140175280(uVar4,"SDL.gpu.device.create.shaders.spirv",1);

    FUN_140175280(uVar4,"SDL.gpu.device.create.shaders.dxil",1);

  }

  FUN_140175280(uVar4,"SDL.gpu.device.create.shaders.msl",0);

  return;

}




