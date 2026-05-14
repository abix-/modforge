// Address: 0x1402700b0
// Ghidra name: FUN_1402700b0
// ============ 0x1402700b0 FUN_1402700b0 (size=99) ============


undefined4

FUN_1402700b0(longlong param_1,undefined8 param_2,int param_3,undefined2 param_4,undefined2 param_5)



{

  char cVar1;

  int iVar2;

  undefined1 local_48 [2];

  char local_46;

  

  if (param_3 != 5) {

    cVar1 = FUN_1402086e0(param_4,param_5);

    if (cVar1 == '\0') {

      return 0;

    }

    if ((param_1 != 0) && (*(longlong *)(param_1 + 0x80) != 0)) {

      iVar2 = FUN_14026ffd0(*(longlong *)(param_1 + 0x80),3,local_48,0x40);

      if (iVar2 != 0x30) {

        return 0;

      }

      if (local_46 != '\'') {

        return 0;

      }

    }

  }

  return 1;

}




