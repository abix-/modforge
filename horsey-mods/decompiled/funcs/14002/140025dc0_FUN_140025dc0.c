// Address: 0x140025dc0
// Ghidra name: FUN_140025dc0
// ============ 0x140025dc0 FUN_140025dc0 (size=50) ============


undefined8 * FUN_140025dc0(longlong param_1)



{

  longlong lVar1;

  

  if ((*(longlong **)(param_1 + 0x28) != (longlong *)0x0) &&

     (lVar1 = (**(code **)(**(longlong **)(param_1 + 0x28) + 0x60))(), lVar1 != 0)) {

    if (*(ulonglong *)(lVar1 + 0x50) < 0x10) {

      return (undefined8 *)(lVar1 + 0x38);

    }

    return *(undefined8 **)(lVar1 + 0x38);

  }

  return (undefined8 *)0x0;

}




