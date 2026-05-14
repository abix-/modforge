// Address: 0x140286130
// Ghidra name: FUN_140286130
// ============ 0x140286130 FUN_140286130 (size=155) ============


undefined8 FUN_140286130(longlong param_1,short *param_2)



{

  char cVar1;

  int iVar2;

  undefined8 uVar3;

  short local_res8 [4];

  short local_res10 [4];

  longlong *local_res18 [2];

  

  uVar3 = 1;

  local_res8[0] = 0;

  local_res10[0] = 0;

  local_res18[0] = (longlong *)0x0;

  if ((*(uint *)(param_1 + 0x24) & 0x10000) != 0) {

    iVar2 = (**(code **)(*DAT_1403fde50 + 0x18))(DAT_1403fde50,param_1 + 4,local_res18,0);

    if (-1 < iVar2) {

      cVar1 = FUN_140286260(local_res18[0],local_res8,local_res10);

      if (((cVar1 != '\0') && (local_res8[0] == *param_2)) && (local_res10[0] == param_2[1])) {

        *(undefined1 *)(param_2 + 2) = 1;

        uVar3 = 0;

      }

    }

    if (local_res18[0] != (longlong *)0x0) {

      (**(code **)(*local_res18[0] + 0x10))();

    }

  }

  return uVar3;

}




