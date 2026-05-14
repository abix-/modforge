// Address: 0x140141d70
// Ghidra name: FUN_140141d70
// ============ 0x140141d70 FUN_140141d70 (size=210) ============


void FUN_140141d70(undefined8 param_1,longlong *param_2,int param_3,char param_4)



{

  longlong lVar1;

  char cVar2;

  ulonglong uVar3;

  int local_88 [2];

  undefined8 local_80;

  undefined4 local_78;

  undefined1 local_74;

  char local_73;

  

  _guard_check_icall();

  if (param_3 == -1) {

    return;

  }

  local_88[0] = 0x652 - (uint)(param_4 != '\0');

  if (param_3 == 5) {

    uVar3 = FUN_140149350();

    lVar1 = *param_2;

    if (param_4 == '\0') {

      if (uVar3 < param_2[9] + 0xfaU) {

        *(undefined1 *)(lVar1 + 0xf0) = 1;

        return;

      }

      *(undefined1 *)(lVar1 + 0xf0) = 0;

    }

    else {

      param_2[9] = uVar3;

      if (*(char *)(lVar1 + 0xf0) != '\0') {

        return;

      }

    }

  }

  cVar2 = FUN_140139420(local_88[0]);

  if (cVar2 != '\0') {

    local_78 = *(undefined4 *)*param_2;

    local_74 = (undefined1)param_3;

    local_80 = param_1;

    local_73 = param_4;

    FUN_14013b140(local_88);

  }

  return;

}




