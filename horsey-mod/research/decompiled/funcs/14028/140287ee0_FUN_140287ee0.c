// Address: 0x140287ee0
// Ghidra name: FUN_140287ee0
// ============ 0x140287ee0 FUN_140287ee0 (size=114) ============


undefined8 FUN_140287ee0(undefined8 param_1,longlong param_2)



{

  char cVar1;

  int iVar2;

  longlong *local_res10 [3];

  

  iVar2 = (**(code **)(*DAT_1403fde60 + 0x18))(DAT_1403fde60,param_2 + 0x1c,local_res10,0);

  if (iVar2 < 0) {

    FUN_1402878d0("Creating DirectInput device",iVar2);

    return 0;

  }

  cVar1 = FUN_140287f60(param_1,local_res10[0],0);

  if (cVar1 == '\0') {

    (**(code **)(*local_res10[0] + 0x10))();

    return 0;

  }

  return 1;

}




