// Address: 0x140197c50
// Ghidra name: FUN_140197c50
// ============ 0x140197c50 FUN_140197c50 (size=32) ============


ulonglong FUN_140197c50(ulonglong *param_1)



{

  ulonglong uVar1;

  

  if (param_1 == (ulonglong *)0x0) {

    return 0;

  }

  uVar1 = *param_1 * 0xff1cd035 + 5;

  *param_1 = uVar1;

  return uVar1 >> 0x20;

}




