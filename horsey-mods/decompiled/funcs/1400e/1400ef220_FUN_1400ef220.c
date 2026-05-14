// Address: 0x1400ef220
// Ghidra name: FUN_1400ef220
// ============ 0x1400ef220 FUN_1400ef220 (size=658) ============


undefined8 FUN_1400ef220(longlong param_1,int *param_2,int *param_3,int *param_4)



{

  byte bVar1;

  int iVar2;

  byte *pbVar3;

  byte bVar4;

  ulonglong *puVar5;

  byte bVar6;

  byte bVar7;

  longlong lVar8;

  

  lVar8 = 0;

  puVar5 = (ulonglong *)(param_1 + 0xb8);

  bVar6 = 0;

  if ((*(longlong *)(param_1 + 0x10) == 0) ||

     (iVar2 = *(int *)(param_1 + 0xc0) - *(int *)puVar5, 0x5b < iVar2)) {

    *puVar5 = *puVar5 + 0x5c;

  }

  else {

    *puVar5 = *(ulonglong *)(param_1 + 0xc0);

    (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),0x5c - iVar2);

  }

  iVar2 = FUN_1400e8ad0(param_1);

  *param_2 = iVar2;

  iVar2 = FUN_1400e8ad0(param_1);

  *param_3 = iVar2;

  if (*(longlong *)(param_1 + 0x10) != 0) {

    iVar2 = (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x28));

    if (iVar2 == 0) goto LAB_1400ef2f5;

    if (*(int *)(param_1 + 0x30) == 0) {

      return 0;

    }

  }

  if (*(ulonglong *)(param_1 + 0xc0) <= *puVar5) {

    return 0;

  }

LAB_1400ef2f5:

  puVar5 = (ulonglong *)(param_1 + 0xb8);

  if ((*param_2 == 0) || (*param_3 <= (int)(0x10000000 / (longlong)*param_2))) {

    if ((*(longlong *)(param_1 + 0x10) == 0) ||

       (iVar2 = *(int *)(param_1 + 0xc0) - *(int *)puVar5, 7 < iVar2)) {

      *puVar5 = *puVar5 + 8;

    }

    else {

      *puVar5 = *(ulonglong *)(param_1 + 0xc0);

      (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),8 - iVar2);

    }

    while (lVar8 != 10) {

      pbVar3 = (byte *)*puVar5;

      lVar8 = lVar8 + 1;

      if (pbVar3 < *(byte **)(param_1 + 0xc0)) {

        bVar7 = *pbVar3;

        pbVar3 = pbVar3 + 1;

        *puVar5 = (ulonglong)pbVar3;

      }

      else {

        bVar7 = 0;

        if (*(int *)(param_1 + 0x30) != 0) {

          FUN_1400ed820(param_1);

          bVar7 = *(byte *)*puVar5;

          pbVar3 = (byte *)*puVar5 + 1;

          *puVar5 = (ulonglong)pbVar3;

        }

      }

      if (pbVar3 < *(byte **)(param_1 + 0xc0)) {

        bVar4 = *pbVar3;

        pbVar3 = pbVar3 + 1;

        *puVar5 = (ulonglong)pbVar3;

      }

      else if (*(int *)(param_1 + 0x30) == 0) {

        bVar4 = 0;

      }

      else {

        FUN_1400ed820();

        bVar4 = *(byte *)*puVar5;

        pbVar3 = (byte *)*puVar5 + 1;

        *puVar5 = (ulonglong)pbVar3;

      }

      if (pbVar3 < *(byte **)(param_1 + 0xc0)) {

        pbVar3 = pbVar3 + 1;

        *puVar5 = (ulonglong)pbVar3;

      }

      else if (*(int *)(param_1 + 0x30) != 0) {

        FUN_1400ed820();

        *puVar5 = *puVar5 + 1;

        pbVar3 = (byte *)*puVar5;

      }

      if (pbVar3 < *(byte **)(param_1 + 0xc0)) {

        bVar1 = *pbVar3;

        *puVar5 = (ulonglong)(pbVar3 + 1);

      }

      else if (*(int *)(param_1 + 0x30) == 0) {

        bVar1 = 0;

      }

      else {

        FUN_1400ed820(param_1);

        bVar1 = *(byte *)*puVar5;

        *puVar5 = (ulonglong)((byte *)*puVar5 + 1);

      }

      bVar6 = bVar6 | bVar1;

      if (*(longlong *)(param_1 + 0x10) == 0) {

LAB_1400ef457:

        if (*(ulonglong *)(param_1 + 0xc0) <= *puVar5) goto LAB_1400ef48d;

      }

      else {

        iVar2 = (**(code **)(param_1 + 0x20))(*(undefined8 *)(param_1 + 0x28));

        if (iVar2 != 0) {

          if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400ef48d;

          goto LAB_1400ef457;

        }

      }

      if (bVar4 != 8) {

LAB_1400ef48d:

        *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 200);

        return 0;

      }

      if (bVar7 == 0) {

        *param_4 = ((bVar6 & 0x10) != 0) + 3;

        return 1;

      }

    }

  }

  else {

    *puVar5 = *(ulonglong *)(param_1 + 200);

  }

  return 0;

}




