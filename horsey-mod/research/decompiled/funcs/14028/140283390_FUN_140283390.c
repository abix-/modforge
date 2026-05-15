// Address: 0x140283390
// Ghidra name: FUN_140283390
// ============ 0x140283390 FUN_140283390 (size=262) ============


undefined8 FUN_140283390(longlong param_1)



{

  int iVar1;

  char *pcVar2;

  int iVar3;

  int iVar4;

  undefined2 local_48;

  undefined8 local_46;

  undefined8 uStack_3e;

  undefined8 local_36;

  undefined8 uStack_2e;

  undefined8 local_26;

  undefined4 local_1e;

  undefined2 local_1a;

  

  iVar4 = 0;

  do {

    local_48 = 0x203;

    local_26 = 0;

    local_1e = 0;

    local_46 = 0;

    uStack_3e = 0;

    local_1a = 0;

    local_36 = 0;

    uStack_2e = 0;

    iVar1 = FUN_140195730(*(undefined8 *)(param_1 + 0x80),&local_48,0x30);

    iVar3 = 0;

    if (iVar1 == 0x30) goto LAB_140283405;

    iVar4 = iVar4 + 1;

  } while (iVar4 < 8);

  iVar3 = 0;

  if (iVar1 < 0x30) {

    pcVar2 = "SInput device SDL Features GET command could not write";

  }

  else {

LAB_140283405:

    while( true ) {

      FUN_1401492f0(1);

      iVar4 = FUN_140193800(*(undefined8 *)(param_1 + 0x80),&local_48,0x40,0);

      if (iVar4 < 0) break;

      if (((iVar4 == 0x40) && ((char)local_48 == '\x02')) && (local_48._1_1_ == '\x02')) {

        FUN_140283130(param_1,&local_46);

        return 1;

      }

      iVar3 = iVar3 + 1;

      if (99 < iVar3) {

        return 0;

      }

    }

    pcVar2 = "SInput device SDL Features GET command could not read";

  }

  FUN_14012e850(pcVar2);

  return 0;

}




