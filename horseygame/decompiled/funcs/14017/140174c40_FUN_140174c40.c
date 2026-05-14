// Address: 0x140174c40
// Ghidra name: FUN_140174c40
// ============ 0x140174c40 FUN_140174c40 (size=234) ============


ulonglong FUN_140174c40(int param_1,char *param_2,ulonglong param_3)



{

  int iVar1;

  char cVar2;

  double dVar3;

  undefined8 *local_res18;

  int *local_res20;

  

  local_res18 = (undefined8 *)0x0;

  if (((param_1 != 0) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) {

    FUN_1401aaff0(DAT_1403fc450,param_1,&local_res18);

    if (local_res18 != (undefined8 *)0x0) {

      FUN_140179b40(local_res18[1]);

      local_res20 = (int *)0x0;

      cVar2 = FUN_1401aaff0(*local_res18,param_2,&local_res20);

      if (cVar2 != '\0') {

        iVar1 = *local_res20;

        if (iVar1 == 2) {

          param_3 = thunk_FUN_1402d8b40(*(undefined8 *)(local_res20 + 2),0,0);

        }

        else if (iVar1 == 3) {

          param_3 = *(ulonglong *)(local_res20 + 2);

        }

        else if (iVar1 == 4) {

          dVar3 = (double)thunk_FUN_1402e1d50((double)(float)local_res20[2]);

          param_3 = (ulonglong)dVar3;

        }

        else if (iVar1 == 5) {

          param_3 = (ulonglong)*(byte *)(local_res20 + 2);

        }

      }

      FUN_140179b60(local_res18[1]);

    }

  }

  return param_3;

}




