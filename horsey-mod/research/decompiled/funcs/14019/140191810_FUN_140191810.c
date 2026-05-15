// Address: 0x140191810
// Ghidra name: FUN_140191810
// ============ 0x140191810 FUN_140191810 (size=129) ============


uint FUN_140191810(ulonglong param_1)



{

  uint uVar1;

  uint uVar2;

  uint uVar3;

  uint uVar4;

  

  uVar4 = 0xedb88320;

  if ((param_1 & 1) != 0) {

    uVar4 = 0;

  }

  uVar4 = uVar4 ^ (uint)(param_1 >> 1) & 0x7fffffff;

  uVar2 = 0xedb88320;

  uVar3 = 0xedb88320;

  uVar1 = 0xedb88320;

  if ((uVar4 & 1) != 0) {

    uVar1 = 0;

  }

  uVar1 = uVar1 ^ uVar4 >> 1;

  uVar4 = 0;

  if ((uVar1 & 1) != 0) {

    uVar3 = 0;

  }

  uVar3 = uVar3 ^ uVar1 >> 1;

  uVar1 = uVar2;

  if ((uVar3 & 1) != 0) {

    uVar1 = uVar4;

  }

  uVar1 = uVar1 ^ uVar3 >> 1;

  uVar3 = uVar2;

  if ((uVar1 & 1) != 0) {

    uVar3 = uVar4;

  }

  uVar3 = uVar3 ^ uVar1 >> 1;

  if ((uVar3 & 1) != 0) {

    uVar2 = uVar4;

  }

  uVar2 = uVar2 ^ uVar3 >> 1;

  uVar4 = 0xedb88320;

  if ((uVar2 & 1) != 0) {

    uVar4 = 0;

  }

  uVar4 = uVar4 ^ uVar2 >> 1;

  uVar1 = 0x12b88320;

  if ((uVar4 & 1) != 0) {

    uVar1 = 0xff000000;

  }

  return uVar1 ^ uVar4 >> 1;

}




