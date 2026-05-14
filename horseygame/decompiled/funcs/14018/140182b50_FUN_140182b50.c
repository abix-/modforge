// Address: 0x140182b50
// Ghidra name: FUN_140182b50
// ============ 0x140182b50 FUN_140182b50 (size=92) ============


ulonglong FUN_140182b50(longlong param_1,undefined4 param_2,undefined2 *param_3)



{

  char cVar1;

  ulonglong uVar2;

  ulonglong local_res8;

  

  if ((param_1 != 0) &&

     (cVar1 = FUN_1401aaff0(*(undefined8 *)(param_1 + 8),param_2,&local_res8), cVar1 != '\0')) {

    if (param_3 == (undefined2 *)0x0) {

      return local_res8 & 0xffff;

    }

    *param_3 = (short)(local_res8 >> 0x10);

    return local_res8 & 0xffff;

  }

  uVar2 = FUN_140182560(param_2,param_3);

  return uVar2;

}




