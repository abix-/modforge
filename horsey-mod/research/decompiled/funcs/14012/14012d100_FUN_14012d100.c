// Address: 0x14012d100
// Ghidra name: FUN_14012d100
// ============ 0x14012d100 FUN_14012d100 (size=94) ============


longlong FUN_14012d100(ulonglong *param_1,longlong param_2,int param_3)



{

  ulonglong uVar1;

  ulonglong uVar2;

  ulonglong uVar3;

  

  if (param_3 == 0) {

    uVar2 = *param_1;

  }

  else if (param_3 == 1) {

    uVar2 = param_1[1];

  }

  else {

    if (param_3 != 2) {

      FUN_14012e850("Unknown value for \'whence\'");

      return -1;

    }

    uVar2 = param_1[2];

  }

  uVar1 = *param_1;

  uVar3 = uVar2 + param_2;

  if (uVar2 + param_2 < uVar1) {

    uVar3 = uVar1;

  }

  if (param_1[2] < uVar3) {

    uVar3 = param_1[2];

  }

  param_1[1] = uVar3;

  return uVar3 - uVar1;

}




