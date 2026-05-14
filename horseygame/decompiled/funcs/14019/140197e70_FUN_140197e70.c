// Address: 0x140197e70
// Ghidra name: FUN_140197e70
// ============ 0x140197e70 FUN_140197e70 (size=431) ============


ulonglong FUN_140197e70(longlong *param_1,longlong *param_2)



{

  longlong lVar1;

  undefined8 uVar2;

  longlong *plVar3;

  char cVar4;

  ulonglong in_RAX;

  longlong lVar5;

  bool bVar6;

  

  if ((param_1 == (longlong *)0x0) || (param_2 == (longlong *)0x0)) {

    return in_RAX & 0xffffffffffffff00;

  }

  lVar1 = *param_1;

  *param_2 = 0;

  param_2[1] = 0;

  param_2[2] = 0;

  param_2[3] = 0;

  param_2[4] = 0;

  param_2[5] = 0;

  param_2[6] = 0;

  lVar5 = lVar1;

  if (*(char *)(lVar1 + 200) != '\0') {

    lVar5 = 0;

  }

  *param_2 = lVar5;

  *(int *)((longlong)param_2 + 0xc) = (int)param_1[7];

  *(int *)(param_2 + 1) = (int)param_1[1];

  param_2[2] = param_1[5];

  param_2[3] = param_1[3];

  param_2[4] = param_1[8];

  param_2[5] = param_1[9];

  param_2[6] = param_1[10];

  uVar2 = *(undefined8 *)(lVar1 + 0x30);

  FUN_140179b40(uVar2);

  if (param_1[0xc] != 0) {

    *(longlong *)(param_1[0xc] + 0x58) = param_1[0xb];

  }

  *(longlong *)(param_1[0xb] + 0x60) = param_1[0xc];

  param_1[0xc] = 0;

  param_1[0xb] = 0;

  plVar3 = *(longlong **)(lVar1 + 0xc0);

  if (((plVar3 != (longlong *)0x0) && (param_1 != plVar3)) && (*(longlong *)(lVar1 + 0x98) == 0)) {

    plVar3[0xb] = lVar1 + 0x38;

    lVar5 = *(longlong *)(lVar1 + 0x98);

    plVar3[0xc] = lVar5;

    if (lVar5 != 0) {

      *(longlong **)(lVar5 + 0x58) = plVar3;

    }

    *(longlong **)(lVar1 + 0x98) = plVar3;

    FUN_140138fb0(plVar3[2] + 0x38,1);

    cVar4 = (**(code **)(lVar1 + 0x18))(*(undefined8 *)(lVar1 + 0x28),plVar3);

    if (cVar4 == '\0') {

      FUN_140138fb0(plVar3[2] + 0x38,0xffffffff);

      FUN_140179b60(uVar2);

      bVar6 = true;

      goto LAB_140197fe4;

    }

  }

  FUN_140179b60(uVar2);

  bVar6 = true;

  if ((plVar3 != (longlong *)0x0) && (param_1 == plVar3)) {

    bVar6 = *(char *)(lVar1 + 200) == '\0';

    (**(code **)(lVar1 + 0x20))(*(undefined8 *)(lVar1 + 0x28));

    FUN_140179b30(*(undefined8 *)(lVar1 + 0x30));

    FUN_1401841e0(lVar1);

  }

LAB_140197fe4:

  FUN_140138fb0(param_1[2] + 0x38,0xffffffff);

  FUN_1401841e0(param_1);

  return (ulonglong)bVar6;

}




