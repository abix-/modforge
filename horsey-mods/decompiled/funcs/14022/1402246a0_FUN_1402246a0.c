// Address: 0x1402246a0
// Ghidra name: FUN_1402246a0
// ============ 0x1402246a0 FUN_1402246a0 (size=598) ============


void FUN_1402246a0(longlong param_1,HWND param_2)



{

  uint uVar1;

  undefined4 uVar2;

  int iVar3;

  HIMC pHVar4;

  longlong lVar5;

  longlong lVar6;

  longlong lVar7;

  undefined4 local_res8 [2];

  undefined4 local_res18 [2];

  undefined4 local_res20 [2];

  undefined1 local_48 [32];

  

  local_res20[0] = 0;

  local_res18[0] = 0;

  local_res8[0] = 0;

  *(undefined2 *)(param_1 + 0x174) = 0;

  uVar1 = FUN_140224350(param_1,0);

  if (uVar1 == 0) {

    return;

  }

  pHVar4 = ImmGetContext(param_2);

  if (pHVar4 == (HIMC)0x0) {

    return;

  }

  if (*(code **)(param_1 + 600) != (code *)0x0) {

    uVar1 = (**(code **)(param_1 + 600))(pHVar4,0,0,local_res20,local_res18,local_res8);

    uVar2 = 0;

    if (uVar1 != 0) {

      if (0x10 < uVar1) {

        uVar1 = 0x10;

      }

      uVar2 = (**(code **)(param_1 + 600))(pHVar4,uVar1,local_48,local_res20,local_res18,local_res8)

      ;

    }

    FUN_14012fcd0(param_1 + 0x174,local_48,uVar2);

    goto LAB_1402248d3;

  }

  lVar5 = (**(code **)(param_1 + 0x268))(pHVar4);

  if (uVar1 < 0x4040405) {

    if (uVar1 == 0x4040404) {

LAB_1402247d8:

      lVar6 = (**(code **)(param_1 + 0x278))(*(undefined8 *)(lVar5 + 0x138));

      lVar6 = *(longlong *)(lVar6 + 0x18);

    }

    else {

      if (uVar1 != 0x4010804) {

        if (uVar1 != 0x4020404) {

          if (uVar1 == 0x4020804) {

            lVar6 = (**(code **)(param_1 + 0x278))(*(undefined8 *)(lVar5 + 0x138));

            lVar6 = *(longlong *)(lVar6 + 0x20);

            goto LAB_140224882;

          }

          if (uVar1 != 0x4030404) goto LAB_1402248af;

        }

        goto LAB_1402247d8;

      }

      uVar1 = FUN_140224350(param_1,1);

      lVar6 = 0x1c;

      if (1 < uVar1) {

        lVar6 = 0x20;

      }

      lVar7 = (**(code **)(param_1 + 0x278))(*(undefined8 *)(lVar5 + 0x138));

      lVar6 = *(longlong *)(lVar7 + lVar6);

    }

    if (lVar6 != 0) {

      iVar3 = *(int *)(lVar6 + 0x9c);

      lVar6 = lVar6 + 0x38;

LAB_14022488e:

      if (lVar6 != 0) {

        uVar1 = iVar3 + 1;

        if (0xf < uVar1) {

          uVar1 = 0x10;

        }

        FUN_14012fcd0(param_1 + 0x174,lVar6,uVar1);

      }

    }

  }

  else if (((uVar1 == 0x5010404) || (uVar1 == 0x5020404)) || (uVar1 == 0x5030804)) {

    lVar6 = (**(code **)(param_1 + 0x278))(*(undefined8 *)(lVar5 + 0x138));

    if (*(longlong *)(lVar6 + 4) != 0) {

      lVar6 = *(longlong *)(*(longlong *)(lVar6 + 4) + 0x18);

LAB_140224882:

      if (lVar6 == 0) goto LAB_1402248af;

      iVar3 = *(int *)(lVar6 + 0x60);

      lVar6 = lVar6 + 0x40;

      goto LAB_14022488e;

    }

  }

LAB_1402248af:

  (**(code **)(param_1 + 0x280))(*(undefined8 *)(lVar5 + 0x138));

  (**(code **)(param_1 + 0x270))(pHVar4);

LAB_1402248d3:

  ImmReleaseContext(param_2,pHVar4);

  FUN_140224c40(param_1);

  return;

}




