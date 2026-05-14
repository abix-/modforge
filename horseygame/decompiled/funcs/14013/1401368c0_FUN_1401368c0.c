// Address: 0x1401368c0
// Ghidra name: FUN_1401368c0
// ============ 0x1401368c0 FUN_1401368c0 (size=337) ============


undefined * FUN_1401368c0(undefined4 param_1)



{

  undefined *puVar1;

  char cVar2;

  int iVar3;

  longlong lVar4;

  longlong lVar5;

  undefined8 *puVar6;

  uint uVar7;

  ulonglong uVar8;

  undefined **ppuVar9;

  

  lVar4 = FUN_14016dcf0();

  if (lVar4 == 0) {

    FUN_14012e850("Video subsystem not initialized");

    return (undefined *)0x0;

  }

  lVar5 = FUN_140142960("SDL_GPU_DRIVER");

  if ((lVar5 == 0) && (lVar5 = FUN_140174e70(param_1,"SDL.gpu.device.create.name",0), lVar5 == 0)) {

    uVar8 = 0;

    puVar1 = PTR_PTR_1403ded10;

    while (puVar1 != (undefined *)0x0) {

      cVar2 = (**(code **)(puVar1 + 8))(lVar4,param_1);

      if (cVar2 != '\0') {

        return (&PTR_PTR_1403ded10)[uVar8];

      }

      uVar7 = (int)uVar8 + 1;

      uVar8 = (ulonglong)uVar7;

      puVar1 = (&PTR_PTR_1403ded10)[uVar7];

    }

    FUN_14012e850("No supported SDL_GPU backend found!");

  }

  else {

    uVar8 = 0;

    if (PTR_PTR_1403ded10 != (undefined *)0x0) {

      ppuVar9 = &PTR_PTR_1403ded10;

      puVar6 = (undefined8 *)PTR_PTR_1403ded10;

      do {

        iVar3 = FUN_14012ef60(lVar5,*puVar6);

        if ((iVar3 == 0) && (cVar2 = (**(code **)(*ppuVar9 + 8))(lVar4,param_1), cVar2 != '\0')) {

          return (&PTR_PTR_1403ded10)[uVar8];

        }

        uVar7 = (int)uVar8 + 1;

        puVar6 = (undefined8 *)(&PTR_PTR_1403ded10)[uVar7];

        ppuVar9 = &PTR_PTR_1403ded10 + uVar7;

        uVar8 = (ulonglong)uVar7;

      } while (puVar6 != (undefined8 *)0x0);

    }

    FUN_14012e850("SDL_HINT_GPU_DRIVER %s unsupported!",lVar5);

  }

  return (undefined *)0x0;

}




