// Address: 0x1402eff44
// Ghidra name: FUN_1402eff44
// ============ 0x1402eff44 FUN_1402eff44 (size=376) ============


/* WARNING: Globals starting with '_' overlap smaller symbols at the same address */



int FUN_1402eff44(ushort *param_1,byte *param_2,ulonglong param_3,longlong param_4)



{

  int iVar1;

  longlong *plVar2;

  int iVar3;

  

  if ((param_2 == (byte *)0x0) || (param_3 == 0)) {

    _DAT_1403ff648 = 0;

  }

  else {

    if (*param_2 != 0) {

      if (*(char *)(param_4 + 0x28) == '\0') {

        FUN_1402d74e0(param_4);

      }

      plVar2 = *(longlong **)(param_4 + 0x18);

      iVar3 = *(int *)((longlong)plVar2 + 0xc);

      if (iVar3 != 0xfde9) {

        if (plVar2[0x27] == 0) {

          if (param_1 != (ushort *)0x0) {

            *param_1 = (ushort)*param_2;

          }

          return 1;

        }

        if (*(short *)(*plVar2 + (ulonglong)*param_2 * 2) < 0) {

          iVar1 = (int)plVar2[1];

          if ((((1 < iVar1) && (iVar1 <= (int)param_3)) &&

              (iVar3 = FUN_1402f3150(iVar3,9,param_2,iVar1,param_1,param_1 != (ushort *)0x0),

              iVar3 != 0)) ||

             (((ulonglong)(longlong)*(int *)(*(longlong *)(param_4 + 0x18) + 8) <= param_3 &&

              (param_2[1] != 0)))) {

            return *(int *)(*(longlong *)(param_4 + 0x18) + 8);

          }

        }

        else {

          iVar3 = FUN_1402f3150(iVar3,9,param_2,1,param_1,param_1 != (ushort *)0x0);

          if (iVar3 != 0) {

            return 1;

          }

        }

        *(undefined1 *)(param_4 + 0x30) = 1;

        *(undefined4 *)(param_4 + 0x2c) = 0x2a;

        return -1;

      }

      iVar3 = FUN_1402f03fc(param_1,param_2,param_3,&DAT_1403ff648,param_4);

      if (iVar3 < 0) {

        return -1;

      }

      return iVar3;

    }

    if (param_1 != (ushort *)0x0) {

      *param_1 = 0;

    }

  }

  return 0;

}




