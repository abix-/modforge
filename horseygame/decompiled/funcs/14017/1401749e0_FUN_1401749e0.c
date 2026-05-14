// Address: 0x1401749e0
// Ghidra name: FUN_1401749e0
// ============ 0x1401749e0 FUN_1401749e0 (size=257) ============


undefined1 FUN_1401749e0(int param_1,char *param_2,char param_3)



{

  int iVar1;

  char cVar2;

  undefined1 uVar3;

  undefined8 *local_res20;

  int *local_18 [2];

  

  uVar3 = param_3 != '\0';

  local_res20 = (undefined8 *)0x0;

  if ((((param_1 != 0) && (param_2 != (char *)0x0)) && (*param_2 != '\0')) &&

     (FUN_1401aaff0(DAT_1403fc450,param_1,&local_res20), local_res20 != (undefined8 *)0x0)) {

    FUN_140179b40(local_res20[1]);

    local_18[0] = (int *)0x0;

    cVar2 = FUN_1401aaff0(*local_res20,param_2,local_18);

    if (cVar2 != '\0') {

      iVar1 = *local_18[0];

      if (iVar1 == 2) {

        uVar3 = FUN_1401429e0(*(undefined8 *)(local_18[0] + 2),param_3);

      }

      else if (iVar1 == 3) {

        uVar3 = *(longlong *)(local_18[0] + 2) != 0;

      }

      else if (iVar1 == 4) {

        if ((float)local_18[0][2] == 0.0) {

          uVar3 = 0;

        }

        else {

          uVar3 = 1;

        }

      }

      else if (iVar1 == 5) {

        uVar3 = (undefined1)local_18[0][2];

      }

    }

    FUN_140179b60(local_res20[1]);

  }

  return uVar3;

}




