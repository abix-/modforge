// Address: 0x14015ad00
// Ghidra name: FUN_14015ad00
// ============ 0x14015ad00 FUN_14015ad00 (size=239) ============


void FUN_14015ad00(undefined8 param_1,undefined4 *param_2,byte param_3,char param_4)



{

  char cVar1;

  ulonglong uVar2;

  int local_88 [2];

  undefined8 local_80;

  undefined4 local_78;

  undefined1 local_74;

  char local_73;

  

  uVar2 = (ulonglong)param_3;

  local_88[0] = 0x604 - (uint)(param_4 != '\0');

  if (*(char *)(param_2 + 0x10) != '\0') {

    if (param_3 == 0) {

      uVar2 = 1;

    }

    else if (param_3 == 1) {

      uVar2 = 0;

    }

    else if (param_3 == 2) {

      uVar2 = 3;

    }

    else if (param_3 == 3) {

      uVar2 = 2;

    }

  }

  if ((((int)uVar2 < (int)param_2[0x1c]) &&

      (param_4 != *(char *)(uVar2 + *(longlong *)(param_2 + 0x1e)))) &&

     ((cVar1 = FUN_14015a640(), cVar1 == '\0' || (param_4 == '\0')))) {

    *(char *)(uVar2 + *(longlong *)(param_2 + 0x1e)) = param_4;

    *(undefined8 *)(param_2 + 0x4e) = param_1;

    cVar1 = FUN_140139420(local_88[0]);

    if (cVar1 != '\0') {

      local_78 = *param_2;

      local_80 = param_1;

      local_74 = (char)uVar2;

      local_73 = param_4;

      FUN_14013b140(local_88);

    }

  }

  return;

}




