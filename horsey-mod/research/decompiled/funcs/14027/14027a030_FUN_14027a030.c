// Address: 0x14027a030
// Ghidra name: FUN_14027a030
// ============ 0x14027a030 FUN_14027a030 (size=177) ============


undefined8

FUN_14027a030(longlong param_1,undefined4 param_2,undefined8 param_3,int param_4,char param_5)



{

  char cVar1;

  undefined1 local_28;

  byte local_27;

  undefined1 local_26;

  undefined1 local_25;

  undefined1 local_24;

  undefined1 local_23;

  undefined8 local_22;

  undefined8 uStack_1a;

  

  local_27 = *(byte *)(param_1 + 0x28) | 4;

  local_24 = (undefined1)param_2;

  local_26 = (undefined1)((uint)param_2 >> 0x10);

  local_28 = 0x16;

  local_25 = (undefined1)((uint)param_2 >> 8);

  local_22 = 0;

  uStack_1a = 0;

  local_23 = (undefined1)param_4;

  FUN_1402f8e20(&local_22,param_3,(longlong)param_4);

  cVar1 = FUN_140279fc0(param_1,&local_28,0x16,param_5);

  if (cVar1 != '\0') {

    if (param_5 == '\0') {

      return 1;

    }

    cVar1 = FUN_140279b60(param_1,0x22,&LAB_140279680);

    if (cVar1 != '\0') {

      if (*(char *)(param_1 + 0x30) == '\0') {

        return 1;

      }

      FUN_14012e850("Write memory failed: %u",*(char *)(param_1 + 0x30));

    }

  }

  return 0;

}




