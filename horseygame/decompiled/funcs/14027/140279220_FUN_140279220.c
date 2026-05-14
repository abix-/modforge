// Address: 0x140279220
// Ghidra name: FUN_140279220
// ============ 0x140279220 FUN_140279220 (size=240) ============


void FUN_140279220(longlong param_1,undefined8 param_2)



{

  byte bVar1;

  int iVar2;

  char cVar3;

  undefined8 uVar4;

  char *pcVar5;

  undefined8 local_28;

  undefined8 uStack_20;

  undefined8 local_18;

  undefined4 local_10;

  undefined1 local_c;

  

  iVar2 = *(int *)(param_1 + 0x1c);

  bVar1 = *(byte *)(param_1 + 0x2f);

  local_18 = 0;

  local_10 = 0;

  local_c = 0;

  local_28 = 0;

  uStack_20 = 0;

  FUN_140278670(&local_28,param_1 + 0x2d);

  FUN_140278840(param_1,param_2,&local_28);

  if (*(int *)(param_1 + 0x1c) != 0x83) {

    FUN_140279e40(param_2,*(undefined1 *)(param_1 + 0x32));

  }

  FUN_140279cd0(param_1);

  pcVar5 = "DISCONNECTED";

  if ((bVar1 & 2) != 0) {

    pcVar5 = "CONNECTED";

  }

  FUN_14012e080(7,"HIDAPI Wii: Status update, extension %s",pcVar5);

  if (*(char *)(param_1 + 0x2a) == '\0') {

    if ((iVar2 != 0x80) != ((bVar1 & 2) != 0)) {

      *(undefined1 *)(param_1 + 0x60) = 1;

    }

  }

  else {

    cVar3 = FUN_140279690(param_1,1);

    if (cVar3 != '\0') {

      uVar4 = FUN_140149350();

      *(undefined8 *)(param_1 + 0x58) = uVar4;

    }

  }

  return;

}




