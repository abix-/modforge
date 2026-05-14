// Address: 0x14017c310
// Ghidra name: FUN_14017c310
// ============ 0x14017c310 FUN_14017c310 (size=95) ============


bool FUN_14017c310(longlong param_1,longlong param_2)



{

  longlong lVar1;

  char cVar2;

  

  if ((((*(longlong *)(param_1 + 0xe8) == *(longlong *)(param_2 + 0x38)) &&

       (lVar1 = *(longlong *)(param_2 + 0x48), *(longlong *)(param_1 + 0xf0) == lVar1)) &&

      ((lVar1 == 0 || (*(int *)(param_1 + 0x118) == *(int *)(lVar1 + 0x10))))) &&

     ((*(longlong *)(param_1 + 0x48) == 0 ||

      (*(int *)(param_1 + 0x11c) == *(int *)(*(longlong *)(param_1 + 0x48) + 0x10))))) {

    *(longlong *)(param_1 + 0xb8) = param_2;

    return true;

  }

  cVar2 = FUN_14017bf00();

  return cVar2 != '\0';

}




