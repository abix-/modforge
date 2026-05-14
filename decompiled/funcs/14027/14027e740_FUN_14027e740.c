// Address: 0x14027e740
// Ghidra name: FUN_14027e740
// ============ 0x14027e740 FUN_14027e740 (size=329) ============


undefined8 FUN_14027e740(longlong param_1)



{

  longlong lVar1;

  char cVar2;

  int iVar3;

  undefined4 uVar4;

  longlong lVar5;

  undefined8 uVar6;

  longlong lVar7;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined8 uStack_10;

  

  lVar1 = *(longlong *)(param_1 + 0x70);

  lVar7 = 0;

  local_28 = 0;

  uStack_20 = 0;

  local_18 = 0;

  uStack_10 = 0;

  if ((*(int *)(param_1 + 0x8c) < 1) ||

     (lVar5 = FUN_1401581c0(**(undefined4 **)(param_1 + 0x90)), lVar5 == 0)) {

    uVar6 = 0;

  }

  else {

    switch(*(undefined2 *)(param_1 + 0x22)) {

    case 0xc24f:

      lVar7 = 0xc;

      break;

    case 0xc294:

      lVar7 = 0x1b;

      break;

    case 0xc298:

    case 0xc29a:

      lVar7 = 8;

      break;

    case 0xc299:

    case 0xc29b:

      lVar7 = 0xb;

    }

    do {

      iVar3 = FUN_140193780(*(undefined8 *)(param_1 + 0x80),&local_28,lVar7);

      if (iVar3 < 0) {

        FUN_140208230(param_1,**(undefined4 **)(param_1 + 0x90));

        return 0;

      }

      if (((iVar3 == lVar7) && (cVar2 = FUN_14027ebd0(param_1,lVar5,&local_28,lVar7), cVar2 != '\0')

          ) && (*(char *)(lVar1 + 0x20) == '\0')) {

        *(undefined1 *)(lVar1 + 0x20) = 1;

        uVar4 = FUN_14027fa20("SDL_HIDAPI_LG4FF_RANGE",0x28,900);

        FUN_14027f720(param_1,uVar4);

        FUN_14027f5a0(param_1,0);

      }

    } while (0 < iVar3);

    uVar6 = 1;

  }

  return uVar6;

}




