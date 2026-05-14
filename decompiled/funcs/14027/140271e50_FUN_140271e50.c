// Address: 0x140271e50
// Ghidra name: FUN_140271e50
// ============ 0x140271e50 FUN_140271e50 (size=187) ============


undefined8 FUN_140271e50(longlong param_1,undefined8 param_2,undefined8 param_3)



{

  int iVar1;

  undefined1 local_48;

  char local_47;

  char local_46;

  char local_45;

  char local_44;

  char local_43;

  char local_42;

  

  iVar1 = FUN_14026ffd0(*(undefined8 *)(param_1 + 0x80),0x12,&local_48,0x40);

  if (6 < iVar1) {

    if ((((local_47 != '\0') || (local_46 != '\0')) || (local_45 != '\0')) ||

       (((local_44 != '\0' || (local_43 != '\0')) || (local_42 != '\0')))) {

      FUN_14012ef10(param_2,param_3,"%.2x-%.2x-%.2x-%.2x-%.2x-%.2x",local_42,local_43,local_44,

                    local_45,local_46,local_47);

      return 1;

    }

  }

  return 0;

}




