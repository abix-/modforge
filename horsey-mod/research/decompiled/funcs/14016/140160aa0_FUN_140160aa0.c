// Address: 0x140160aa0
// Ghidra name: FUN_140160aa0
// ============ 0x140160aa0 FUN_140160aa0 (size=288) ============


longlong FUN_140160aa0(longlong param_1,int param_2,int param_3)



{

  undefined4 uVar1;

  int iVar2;

  int iVar3;

  undefined8 *puVar4;

  longlong lVar5;

  longlong lVar6;

  

  puVar4 = (undefined8 *)FUN_1401611a0();

  lVar5 = 0;

  if (param_1 == 0) {

    FUN_14012e850("Parameter \'%s\' is invalid","surface");

  }

  else {

    uVar1 = FUN_140146bc0(param_1);

    iVar2 = FUN_140174c40(uVar1,"SDL.surface.hotspot.x",(longlong)param_2);

    iVar3 = FUN_140174c40(uVar1,"SDL.surface.hotspot.y",(longlong)param_3);

    if ((((iVar2 < 0) || (iVar3 < 0)) || (*(int *)(param_1 + 8) <= iVar2)) ||

       (*(int *)(param_1 + 0xc) <= iVar3)) {

      FUN_14012e850("Cursor hot spot doesn\'t lie within cursor");

    }

    else if ((*(int *)(param_1 + 4) == 0x16362004) ||

            (lVar5 = FUN_140145bb0(param_1,0x16362004), param_1 = lVar5, lVar5 != 0)) {

      if ((code *)*puVar4 == (code *)0x0) {

        lVar6 = FUN_1401841a0(1,0x18);

      }

      else {

        lVar6 = (*(code *)*puVar4)(param_1,iVar2,iVar3);

      }

      if (lVar6 != 0) {

        *(undefined8 *)(lVar6 + 0x10) = puVar4[0x22];

        puVar4[0x22] = lVar6;

      }

      FUN_140146010(lVar5);

      return lVar6;

    }

  }

  return 0;

}




