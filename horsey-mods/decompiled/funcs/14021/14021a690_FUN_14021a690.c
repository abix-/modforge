// Address: 0x14021a690
// Ghidra name: FUN_14021a690
// ============ 0x14021a690 FUN_14021a690 (size=194) ============


void FUN_14021a690(int *param_1,int param_2,int param_3,undefined4 param_4)



{

  char cVar1;

  longlong lVar2;

  int local_88 [2];

  undefined8 local_80;

  int local_78;

  int local_74;

  undefined4 local_70;

  

  if ((param_1 != (int *)0x0) && (*param_1 != 0)) {

    if (param_2 == 0x151) {

      if (param_3 == 0) {

        return;

      }

      if (param_3 == param_1[0x15]) {

        return;

      }

      param_1[0x15] = param_3;

    }

    lVar2 = FUN_14016dcf0();

    if (((lVar2 != 0) && (*(char *)(lVar2 + 0x39d) == '\0')) &&

       (cVar1 = FUN_140139420(param_2), cVar1 != '\0')) {

      local_78 = *param_1;

      local_80 = 0;

      local_88[0] = param_2;

      local_74 = param_3;

      local_70 = param_4;

      FUN_14013b140(local_88);

    }

    if (param_2 == 0x152) {

      FUN_14016f6d0(param_1);

    }

    else if (param_2 == 0x154) {

      thunk_FUN_1401730d0(param_1);

    }

  }

  return;

}




