// Address: 0x1402f5f04
// Ghidra name: truncate_ctrl_z_if_present
// ============ 0x1402f5f04 truncate_ctrl_z_if_present (size=193) ============


/* Library Function - Single Match

    int __cdecl truncate_ctrl_z_if_present(int)

   

   Libraries: Visual Studio 2017 Release, Visual Studio 2019 Release */



int __cdecl truncate_ctrl_z_if_present(int param_1)



{

  byte bVar1;

  int iVar2;

  longlong lVar3;

  int *piVar4;

  short local_res8 [4];

  

  bVar1 = *(byte *)((&DAT_1403ff160)[(longlong)param_1 >> 6] + 0x38 +

                   (ulonglong)(param_1 & 0x3f) * 0x48);

  if (((bVar1 & 0x48) == 0) && ((char)bVar1 < '\0')) {

    lVar3 = FUN_1402eb16c(param_1,0xffffffffffffffff,2);

    if (lVar3 == -1) {

      piVar4 = (int *)FUN_1402e688c();

      if (*piVar4 == 0x83) goto LAB_1402f5fb3;

    }

    else {

      local_res8[0] = 0;

      iVar2 = FUN_1402ea824(param_1,local_res8,1);

      if ((iVar2 == 0) && (local_res8[0] == 0x1a)) {

        iVar2 = FUN_1402f82e8(param_1,lVar3);

        if (iVar2 == -1) goto LAB_1402f5f66;

      }

      lVar3 = FUN_1402eb16c(param_1,0,0);

      if (lVar3 != -1) goto LAB_1402f5fb3;

    }

LAB_1402f5f66:

    piVar4 = (int *)FUN_1402e68b0();

    iVar2 = *piVar4;

  }

  else {

LAB_1402f5fb3:

    iVar2 = 0;

  }

  return iVar2;

}




