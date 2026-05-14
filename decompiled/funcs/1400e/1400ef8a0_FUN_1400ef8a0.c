// Address: 0x1400ef8a0
// Ghidra name: FUN_1400ef8a0
// ============ 0x1400ef8a0 FUN_1400ef8a0 (size=513) ============


undefined8 FUN_1400ef8a0(longlong param_1,int *param_2,int *param_3,uint *param_4)



{

  byte bVar1;

  int iVar2;

  byte *pbVar3;

  int iVar4;

  

  pbVar3 = *(byte **)(param_1 + 0xb8);

  if (pbVar3 < *(byte **)(param_1 + 0xc0)) {

    pbVar3 = pbVar3 + 1;

    *(byte **)(param_1 + 0xb8) = pbVar3;

  }

  else if (*(int *)(param_1 + 0x30) != 0) {

    FUN_1400ed820();

    *(longlong *)(param_1 + 0xb8) = *(longlong *)(param_1 + 0xb8) + 1;

    pbVar3 = *(byte **)(param_1 + 0xb8);

  }

  if (pbVar3 < *(byte **)(param_1 + 0xc0)) {

LAB_1400ef913:

    bVar1 = *pbVar3;

    pbVar3 = pbVar3 + 1;

    *(byte **)(param_1 + 0xb8) = pbVar3;

    if (1 < bVar1) {

      *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 200);

      return 0;

    }

  }

  else if (*(int *)(param_1 + 0x30) != 0) {

    FUN_1400ed820(param_1);

    pbVar3 = *(byte **)(param_1 + 0xb8);

    goto LAB_1400ef913;

  }

  if (*(byte **)(param_1 + 0xc0) <= pbVar3) {

    if (*(int *)(param_1 + 0x30) == 0) {

      return 0;

    }

    FUN_1400ed820(param_1);

    pbVar3 = *(byte **)(param_1 + 0xb8);

  }

  bVar1 = *pbVar3;

  *(byte **)(param_1 + 0xb8) = pbVar3 + 1;

  if (((((bVar1 != 1) && (bVar1 != 2)) && (bVar1 != 3)) && ((bVar1 != 9 && (bVar1 != 10)))) &&

     (bVar1 != 0xb)) {

    return 0;

  }

  if ((*(longlong *)(param_1 + 0x10) == 0) ||

     (iVar4 = *(int *)(param_1 + 0xc0) - (int)(pbVar3 + 1), 8 < iVar4)) {

    *(byte **)(param_1 + 0xb8) = pbVar3 + 10;

  }

  else {

    *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 0xc0);

    (**(code **)(param_1 + 0x18))(*(undefined8 *)(param_1 + 0x28),9 - iVar4);

  }

  iVar4 = FUN_1400e8b80(param_1);

  if (iVar4 < 1) {

    *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 200);

    return 0;

  }

  iVar2 = FUN_1400e8b80(param_1);

  if (0 < iVar2) {

    pbVar3 = *(byte **)(param_1 + 0xb8);

    if (*(byte **)(param_1 + 0xc0) <= pbVar3) {

      if (*(int *)(param_1 + 0x30) == 0) goto LAB_1400efa72;

      FUN_1400ed820(param_1);

      pbVar3 = *(byte **)(param_1 + 0xb8);

    }

    bVar1 = *pbVar3;

    *(byte **)(param_1 + 0xb8) = pbVar3 + 1;

    if ((bVar1 == 8) || (((bVar1 - 0x10 & 0xffffffe7) == 0 && (bVar1 != 0x28)))) {

      if (param_2 != (int *)0x0) {

        *param_2 = iVar4;

      }

      if (param_3 != (int *)0x0) {

        *param_3 = iVar2;

      }

      if (param_4 != (uint *)0x0) {

        *param_4 = (uint)(bVar1 >> 3);

      }

      return 1;

    }

  }

LAB_1400efa72:

  *(undefined8 *)(param_1 + 0xb8) = *(undefined8 *)(param_1 + 200);

  return 0;

}




