// Address: 0x14026e640
// Ghidra name: FUN_14026e640
// ============ 0x14026e640 FUN_14026e640 (size=168) ============


undefined8

FUN_14026e640(longlong param_1,undefined8 param_2,int param_3,short param_4,short param_5)



{

  char cVar1;

  int iVar2;

  undefined1 local_48 [2];

  char local_46;

  

  if ((param_4 != 0x46d) || (param_5 != -0x352f)) {

    if (((param_3 != 4) || (param_4 == 0x54c)) && (cVar1 = FUN_1402086e0(param_4), cVar1 == '\0')) {

      return 0;

    }

    if ((((param_1 != 0) && (*(longlong *)(param_1 + 0x80) != 0)) &&

        ((iVar2 = FUN_14026ffd0(*(longlong *)(param_1 + 0x80),3,local_48,0x40), iVar2 != 8 ||

         (local_46 != '&')))) &&

       ((iVar2 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),0,local_48,0x40), iVar2 != 9 ||

        (local_46 != '&')))) {

      return 0;

    }

  }

  return 1;

}




