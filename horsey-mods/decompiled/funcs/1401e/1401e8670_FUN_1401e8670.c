// Address: 0x1401e8670
// Ghidra name: FUN_1401e8670
// ============ 0x1401e8670 FUN_1401e8670 (size=916) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



void FUN_1401e8670(longlong param_1)



{

  longlong *plVar1;

  undefined4 uVar2;

  ulonglong uVar3;

  longlong *plVar4;

  uint uVar5;

  ulonglong uVar6;

  longlong lVar7;

  undefined4 local_18;

  undefined4 uStack_14;

  undefined4 uStack_10;

  undefined4 uStack_c;

  

  plVar1 = *(longlong **)(param_1 + 0x2e0);

  uVar2 = FUN_14014f090();

  FUN_140175480(uVar2,"SDL.renderer.d3d12.device",0);

  FUN_140175480(uVar2,"SDL.renderer.d3d12.command_queue",0);

  for (lVar7 = *(longlong *)(param_1 + 0x1e8); lVar7 != 0; lVar7 = *(longlong *)(lVar7 + 0x148)) {

    FUN_1401e7cc0(param_1,lVar7);

  }

  if (plVar1 != (longlong *)0x0) {

    uVar3 = 0;

    if ((longlong *)plVar1[2] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[2] + 0x10))();

      plVar1[2] = 0;

    }

    if ((longlong *)plVar1[3] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[3] + 0x10))();

      plVar1[3] = 0;

    }

    if ((longlong *)plVar1[5] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[5] + 0x10))();

      plVar1[5] = 0;

    }

    if ((longlong *)plVar1[6] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[6] + 0x10))();

      plVar1[6] = 0;

    }

    if ((longlong *)plVar1[7] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[7] + 0x10))();

      plVar1[7] = 0;

    }

    if ((longlong *)plVar1[8] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[8] + 0x10))();

      plVar1[8] = 0;

    }

    if ((longlong *)plVar1[9] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[9] + 0x10))();

      plVar1[9] = 0;

    }

    if ((longlong *)plVar1[0xd] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[0xd] + 0x10))();

      plVar1[0xd] = 0;

    }

    if ((longlong *)plVar1[0xf] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[0xf] + 0x10))();

      plVar1[0xf] = 0;

    }

    if ((longlong *)plVar1[0x10] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[0x10] + 0x10))();

      plVar1[0x10] = 0;

    }

    if ((longlong *)plVar1[0x12] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[0x12] + 0x10))();

      plVar1[0x12] = 0;

    }

    plVar1[0x42a] = 0;

    if ((longlong *)plVar1[0x1a] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[0x1a] + 0x10))();

      plVar1[0x1a] = 0;

    }

    if ((longlong *)plVar1[0x14] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[0x14] + 0x10))();

      plVar1[0x14] = 0;

    }

    if ((longlong *)plVar1[0x16] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[0x16] + 0x10))();

      plVar1[0x16] = 0;

    }

    if ((longlong *)plVar1[0x15] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[0x15] + 0x10))();

      plVar1[0x15] = 0;

    }

    if ((longlong *)plVar1[0x17] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[0x17] + 0x10))();

      plVar1[0x17] = 0;

    }

    uVar6 = uVar3;

    if (0 < (int)plVar1[0x1f]) {

      do {

        plVar4 = *(longlong **)(uVar3 + 0x80 + plVar1[0x20]);

        if (plVar4 != (longlong *)0x0) {

          (**(code **)(*plVar4 + 0x10))();

          *(undefined8 *)(uVar3 + 0x80 + plVar1[0x20]) = 0;

        }

        uVar5 = (int)uVar6 + 1;

        uVar3 = uVar3 + 0x88;

        uVar6 = (ulonglong)uVar5;

      } while ((int)uVar5 < (int)plVar1[0x1f]);

      FUN_1401841e0(plVar1[0x20]);

      plVar1[0x20] = 0;

      *(undefined4 *)(plVar1 + 0x1f) = 0;

    }

    if ((longlong *)plVar1[0x1c] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[0x1c] + 0x10))();

      plVar1[0x1c] = 0;

    }

    if ((longlong *)plVar1[0x1d] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[0x1d] + 0x10))();

      plVar1[0x1d] = 0;

    }

    if ((longlong *)plVar1[0x1e] != (longlong *)0x0) {

      (**(code **)(*(longlong *)plVar1[0x1e] + 0x10))();

      plVar1[0x1e] = 0;

    }

    plVar4 = plVar1 + 0x22;

    lVar7 = 0x100;

    do {

      if ((longlong *)*plVar4 != (longlong *)0x0) {

        (**(code **)(*(longlong *)*plVar4 + 0x10))();

        *plVar4 = 0;

      }

      plVar4[3] = 0;

      plVar4 = plVar4 + 4;

      lVar7 = lVar7 + -1;

    } while (lVar7 != 0);

    plVar4 = (longlong *)plVar1[4];

    plVar1[10] = 0;

    plVar1[0x8457] = 0;

    *(undefined4 *)(plVar1 + 0x8458) = 0;

    plVar1[0x8459] = 0;

    *(undefined4 *)(plVar1 + 0x845a) = 0;

    plVar1[0x845b] = 0;

    if (plVar4 != (longlong *)0x0) {

      local_18 = _DAT_14034bca0;

      uStack_14 = _UNK_14034bca4;

      uStack_10 = _UNK_14034bca8;

      uStack_c = _UNK_14034bcac;

      (**(code **)(*plVar4 + 0x18))(plVar4,&local_18,6);

      if ((longlong *)plVar1[4] != (longlong *)0x0) {

        (**(code **)(*(longlong *)plVar1[4] + 0x10))();

        plVar1[4] = 0;

      }

    }

    if (plVar1[1] != 0) {

      FUN_140188670();

      plVar1[1] = 0;

    }

    if (*plVar1 != 0) {

      FUN_140188670();

      *plVar1 = 0;

    }

  }

  return;

}




