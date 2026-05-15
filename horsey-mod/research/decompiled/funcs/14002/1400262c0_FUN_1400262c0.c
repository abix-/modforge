// Address: 0x1400262c0
// Ghidra name: FUN_1400262c0
// ============ 0x1400262c0 FUN_1400262c0 (size=163) ============


ulonglong FUN_1400262c0(longlong *param_1,char *param_2)



{

  FILE *_File;

  errno_t eVar1;

  int iVar2;

  undefined4 extraout_var;

  FILE *local_res18 [2];

  

  local_res18[0] = (FILE *)0x0;

  eVar1 = fopen_s(local_res18,param_2,"w");

  _File = local_res18[0];

  if ((eVar1 == 0) && (local_res18[0] != (FILE *)0x0)) {

    if (*(char *)((longlong)param_1 + 0x9c) != '\0') {

      FUN_1402db0a8(0xef,local_res18[0]);

      FUN_1402db0a8(0xbb,_File);

      FUN_1402db0a8(0xbf,_File);

    }

    (**(code **)(*param_1 + 8))(param_1,_File,0);

    iVar2 = ferror(_File);

    FUN_1402ce288(_File);

    return (ulonglong)(iVar2 == 0);

  }

  return CONCAT44(extraout_var,eVar1) & 0xffffffffffffff00;

}




