// Address: 0x1402dac78
// Ghidra name: FUN_1402dac78
// ============ 0x1402dac78 FUN_1402dac78 (size=171) ============


void FUN_1402dac78(undefined8 param_1,undefined8 param_2,undefined4 param_3)



{

  char cVar1;

  undefined8 uVar2;

  FILE *_File;

  undefined8 local_res8;

  undefined8 local_res10;

  undefined4 local_res18 [2];

  undefined8 local_res20;

  undefined8 local_18 [3];

  

  local_res8 = param_1;

  local_res10 = param_2;

  local_res18[0] = param_3;

  FUN_1402dad44();

  uVar2 = FUN_1402e16a0(2);

  uVar2 = FUN_1402ce15c(&local_res20,uVar2);

  cVar1 = FUN_1402ce480(uVar2);

  if (cVar1 == '\0') {

    uVar2 = FUN_1402e16a0(2);

    FUN_1402f1514(uVar2,0,4);

  }

  local_res20 = FUN_1402dae18(0);

  local_18[0] = FUN_1402e16a0(2);

  ftprintf<>(local_18,&local_res20,&local_res8,&local_res10,local_res18);

  _File = (FILE *)FUN_1402e16a0(2);

  fflush(_File);

                    /* WARNING: Subroutine does not return */

  FUN_1402e1bf8();

}




