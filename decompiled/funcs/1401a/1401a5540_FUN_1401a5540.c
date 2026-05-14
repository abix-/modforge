// Address: 0x1401a5540
// Ghidra name: FUN_1401a5540
// ============ 0x1401a5540 FUN_1401a5540 (size=510) ============


ulonglong FUN_1401a5540(longlong *param_1,longlong param_2,longlong *param_3,longlong param_4,

                       longlong *param_5,int param_6)



{

  int iVar1;

  undefined4 uVar2;

  longlong lVar3;

  ulonglong uVar4;

  bool bVar5;

  

  lVar3 = 0;

  if (param_1 == (longlong *)0x0) {

    if (param_3 != (longlong *)0x0) {

      *param_3 = 0;

    }

    if (param_5 != (longlong *)0x0) {

      *param_5 = 0;

    }

    return 0xfffffffe;

  }

  param_1[0x11] = param_2;

  param_1[0x13] = (longlong)param_3;

  param_1[0x12] = param_4;

  param_1[0x14] = (longlong)param_5;

  param_1[0x16] = param_2;

  if (param_3 != (longlong *)0x0) {

    lVar3 = *param_3;

  }

  *(int *)(param_1 + 0x15) = param_6;

  param_1[0x17] = lVar3;

  param_1[0x18] = 0;

  bVar5 = false;

  if ((param_4 != 0) || (param_5 != (longlong *)0x0)) {

    bVar5 = true;

  }

  if ((((*param_1 != 0) == bVar5) || (*(int *)((longlong)param_1 + 0x84) != 0)) ||

     ((*(uint *)(param_1 + 0x10) != 0 && (param_6 != 4)))) {

LAB_1401a570a:

    if (param_3 == (longlong *)0x0) goto LAB_1401a5712;

  }

  else if (((param_3 == (longlong *)0x0) || (*param_3 == 0)) || (param_2 != 0)) {

    if (((param_5 == (longlong *)0x0) || (*param_5 == 0)) || (param_4 != 0)) {

      *(uint *)(param_1 + 0x10) = (uint)(param_6 == 4) | *(uint *)(param_1 + 0x10);

      if ((*(int *)((longlong)param_1 + 0x74) == 0) && ((int)param_1[0xf] == 0)) {

        iVar1 = FUN_1401a5ab0(param_1);

        if (iVar1 == 0) {

LAB_1401a56b7:

          return (ulonglong)*(uint *)((longlong)param_1 + 0x84);

        }

        if (((*(uint *)(param_1 + 2) & 0x3000) != 0) && (param_2 != 0)) {

          uVar2 = FUN_14019c230((int)param_1[4],param_2,param_1[0x16] - param_2);

          *(undefined4 *)(param_1 + 4) = uVar2;

        }

        if ((((param_6 != 0) && ((int)param_1[5] == 0)) && (param_1[0x17] == 0)) &&

           (*(int *)((longlong)param_1 + 0x74) == 0)) {

          iVar1 = FUN_1401a63b0(param_1,param_6);

          if (iVar1 < 0) goto LAB_1401a56b7;

          *(uint *)(param_1 + 0xf) = (uint)(param_6 == 4);

          if (param_6 == 3) {

            FUN_1402f94c0((longlong)param_1 + 0x292aa,0,0x10000);

            FUN_1402f94c0((longlong)param_1 + 0x192aa,0,0x10000);

            *(undefined4 *)((longlong)param_1 + 0x2c) = 0;

          }

        }

      }

      uVar4 = FUN_1401a6b30(param_1);

      *(int *)((longlong)param_1 + 0x84) = (int)uVar4;

      return uVar4;

    }

    goto LAB_1401a570a;

  }

  *param_3 = 0;

LAB_1401a5712:

  if (param_5 != (longlong *)0x0) {

    *param_5 = 0;

  }

  *(undefined4 *)((longlong)param_1 + 0x84) = 0xfffffffe;

  return 0xfffffffe;

}




