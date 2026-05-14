// Address: 0x1401ee960
// Ghidra name: FUN_1401ee960
// ============ 0x1401ee960 FUN_1401ee960 (size=81) ============


undefined1 FUN_1401ee960(undefined8 param_1,int param_2)



{

  char cVar1;

  undefined1 uVar2;

  int local_res18 [4];

  

  local_res18[0] = 0;

  cVar1 = FUN_14016cde0(param_2);

  if (cVar1 != '\0') {

    cVar1 = FUN_14016c7b0(local_res18);

    if (cVar1 != '\0') {

      if (local_res18[0] != param_2) {

        uVar2 = FUN_14012e850("That operation is not supported");

        return uVar2;

      }

      return 1;

    }

  }

  return 0;

}




