// Address: 0x140197c70
// Ghidra name: FUN_140197c70
// ============ 0x140197c70 FUN_140197c70 (size=42) ============


ulonglong FUN_140197c70(undefined8 param_1,int param_2)



{

  uint uVar1;

  

  if (param_2 < 0) {

    return 0;

  }

  uVar1 = FUN_140197c50();

  return (ulonglong)uVar1 * (longlong)param_2 >> 0x20;

}




