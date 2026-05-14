// Address: 0x140134880
// Ghidra name: FUN_140134880
// ============ 0x140134880 FUN_140134880 (size=236) ============


longlong FUN_140134880(undefined4 param_1)



{

  undefined1 uVar1;

  undefined1 uVar2;

  char cVar3;

  undefined8 *puVar4;

  longlong lVar5;

  

  puVar4 = (undefined8 *)FUN_1401368c0();

  if (puVar4 == (undefined8 *)0x0) {

    return 0;

  }

  FUN_1401aa7a0(&DAT_140319810,*puVar4);

  uVar1 = FUN_1401749e0(param_1,"SDL.gpu.device.create.debugmode",1);

  uVar2 = FUN_1401749e0(param_1,"SDL.gpu.device.create.preferlowpower",0);

  lVar5 = (*(code *)puVar4[2])(uVar1,uVar2,param_1);

  if (lVar5 != 0) {

    *(undefined8 *)(lVar5 + 0x2a0) = *puVar4;

    *(undefined1 *)(lVar5 + 0x2ac) = uVar1;

    cVar3 = FUN_1401749e0(param_1,"SDL.gpu.device.create.feature.depth_clamping",1);

    if (cVar3 == '\0') {

      *(undefined1 *)(lVar5 + 0x2ae) = 1;

    }

    *(bool *)(lVar5 + 0x2ad) = cVar3 == '\0';

    cVar3 = FUN_1401749e0(param_1,"SDL.gpu.device.create.feature.anisotropy",1);

    if (cVar3 == '\0') {

      *(undefined1 *)(lVar5 + 0x2af) = 1;

    }

  }

  return lVar5;

}




