// Address: 0x140275130
// Ghidra name: FUN_140275130
// ============ 0x140275130 FUN_140275130 (size=210) ============


undefined1 FUN_140275130(longlong param_1,undefined1 param_2,longlong param_3,int param_4)



{

  char *pcVar1;

  undefined1 uVar2;

  char cVar3;

  int iVar4;

  ulonglong uVar5;

  undefined1 local_48;

  undefined1 local_47;

  char local_46;

  undefined1 local_45 [45];

  

  pcVar1 = *(char **)(param_1 + 0x70);

  uVar5 = (ulonglong)param_4;

  if (uVar5 < 0x1f) {

    cVar3 = FUN_1402843f0();

    uVar2 = 0;

    if (cVar3 != '\0') {

      local_48 = 4;

      local_46 = *pcVar1;

      *pcVar1 = *pcVar1 + '\x01';

      local_47 = param_2;

      if (param_3 != 0) {

        FUN_1402f8e20(local_45,param_3,uVar5);

      }

      if (param_4 != 0x1e) {

        FUN_1402f94c0(local_45 + uVar5,0,0x1e - uVar5);

      }

      iVar4 = FUN_140284650(param_1,&local_48,0x21);

      if (iVar4 == 0x21) {

        uVar2 = 1;

      }

      else {

        uVar2 = FUN_14012e850("Couldn\'t send command packet");

      }

    }

  }

  else {

    uVar2 = FUN_14012e850("Command data exceeds HID report size");

  }

  return uVar2;

}




