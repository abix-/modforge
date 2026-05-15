// Address: 0x140174af0
// Ghidra name: FUN_140174af0
// ============ 0x140174af0 FUN_140174af0 (size=230) ============


ulonglong FUN_140174af0(int param_1,char *param_2,ulonglong param_3)



{

  int iVar1;

  double dVar2;

  char cVar3;

  undefined8 *local_res20;

  int *local_28 [4];

  

  local_res20 = (undefined8 *)0x0;

  if (((param_1 != 0) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) {

    FUN_1401aaff0(DAT_1403fc450,param_1,&local_res20);

    if (local_res20 != (undefined8 *)0x0) {

      FUN_140179b40(local_res20[1]);

      local_28[0] = (int *)0x0;

      cVar3 = FUN_1401aaff0(*local_res20,param_2,local_28);

      if (cVar3 != '\0') {

        iVar1 = *local_28[0];

        if (iVar1 == 2) {

          dVar2 = (double)thunk_FUN_1402de5ec(*(undefined8 *)(local_28[0] + 2));

          param_3 = (ulonglong)(uint)(float)dVar2;

        }

        else if (iVar1 == 3) {

          param_3 = (ulonglong)(uint)(float)*(longlong *)(local_28[0] + 2);

        }

        else if (iVar1 == 4) {

          param_3 = (ulonglong)(uint)local_28[0][2];

        }

        else if (iVar1 == 5) {

          param_3 = (ulonglong)(uint)(float)*(byte *)(local_28[0] + 2);

        }

      }

      FUN_140179b60(local_res20[1]);

    }

  }

  return param_3;

}




