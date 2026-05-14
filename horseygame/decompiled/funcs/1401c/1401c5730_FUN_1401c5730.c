// Address: 0x1401c5730
// Ghidra name: FUN_1401c5730
// ============ 0x1401c5730 FUN_1401c5730 (size=604) ============


undefined8

FUN_1401c5730(char param_1,longlong param_2,undefined8 param_3,longlong *param_4,undefined4 *param_5

             ,undefined4 *param_6)



{

  longlong lVar1;

  char cVar2;

  uint uVar3;

  int iVar4;

  uint uVar5;

  longlong lVar6;

  undefined8 uVar7;

  ulonglong uVar8;

  undefined8 local_48;

  undefined8 local_40;

  undefined4 local_38;

  undefined4 local_34;

  undefined4 local_30;

  

  lVar1 = *(longlong *)(param_2 + 0x110);

  *param_4 = 0;

  if (param_5 != (undefined4 *)0x0) {

    *param_5 = 0;

  }

  if (param_6 != (undefined4 *)0x0) {

    *param_6 = 0;

  }

  lVar6 = FUN_1401c9f40(param_3);

  if (lVar6 == 0) {

    if (*(char *)(lVar1 + 0x98) != '\0') {

                    /* WARNING: Subroutine does not return */

      FUN_14012e0b0(9,&DAT_14039bf30,"Cannot acquire swapchain texture from an unclaimed window!");

    }

    FUN_14012e850(&DAT_14039bf30,"Cannot acquire swapchain texture from an unclaimed window!");

    return 0;

  }

  if ((*(char *)(lVar6 + 0x148) != '\0') && (cVar2 = FUN_1401caf50(lVar1,lVar6), cVar2 == '\0')) {

    return 0;

  }

  if (param_5 != (undefined4 *)0x0) {

    *param_5 = *(undefined4 *)(lVar6 + 0x140);

  }

  if (param_6 != (undefined4 *)0x0) {

    *param_6 = *(undefined4 *)(lVar6 + 0x144);

  }

  if (*(longlong *)(lVar6 + 0x128 + (ulonglong)*(uint *)(lVar6 + 0x2c) * 8) != 0) {

    if (param_1 == '\0') {

      cVar2 = FUN_1401cbe70(lVar1);

      if (cVar2 == '\0') {

        return 1;

      }

    }

    else {

      cVar2 = FUN_1401cd5b0(lVar1,1,lVar6 + ((ulonglong)*(uint *)(lVar6 + 0x2c) + 0x25) * 8);

      if (cVar2 == '\0') {

        return 0;

      }

    }

    FUN_1401cbf30(lVar1,*(undefined8 *)(lVar6 + 0x128 + (ulonglong)*(uint *)(lVar6 + 0x2c) * 8));

    *(undefined8 *)(lVar6 + 0x128 + (ulonglong)*(uint *)(lVar6 + 0x2c) * 8) = 0;

  }

  uVar3 = (**(code **)(**(longlong **)(lVar6 + 0x18) + 0x120))();

  uVar8 = (ulonglong)uVar3;

  iVar4 = (**(code **)(**(longlong **)(lVar6 + 0x18) + 0x48))

                    (*(longlong **)(lVar6 + 0x18),uVar3,&DAT_1403492f8,

                     *(longlong *)(lVar6 + 0x58 + uVar8 * 0x50) + 0x20);

  if (-1 < iVar4) {

    if (*(int *)(param_2 + 0x140) == *(int *)(param_2 + 0x144)) {

      uVar5 = *(int *)(param_2 + 0x144) + 1;

      *(uint *)(param_2 + 0x144) = uVar5;

      uVar7 = FUN_140184230(*(undefined8 *)(param_2 + 0x138),(ulonglong)uVar5 << 4);

      *(undefined8 *)(param_2 + 0x138) = uVar7;

    }

    *(longlong *)(*(longlong *)(param_2 + 0x138) + (ulonglong)*(uint *)(param_2 + 0x140) * 0x10) =

         lVar6;

    *(uint *)(*(longlong *)(param_2 + 0x138) + 8 + (ulonglong)*(uint *)(param_2 + 0x140) * 0x10) =

         uVar3;

    *(int *)(param_2 + 0x140) = *(int *)(param_2 + 0x140) + 1;

    local_48 = 0;

    local_34 = 0;

    local_30 = 4;

    local_40 = *(undefined8 *)(*(longlong *)(lVar6 + 0x58 + uVar8 * 0x50) + 0x20);

    local_38 = 0;

    (**(code **)(**(longlong **)(param_2 + 0x120) + 0xd0))

              (*(longlong **)(param_2 + 0x120),1,&local_48);

    *param_4 = lVar6 + (uVar8 * 10 + 6) * 8;

    return 1;

  }

  FUN_1401cb240(lVar1,"Could not acquire swapchain!",iVar4);

  return 0;

}




