// Address: 0x1402824e0
// Ghidra name: FUN_1402824e0
// ============ 0x1402824e0 FUN_1402824e0 (size=165) ============


undefined1 FUN_1402824e0(longlong param_1)



{

  short sVar1;

  char cVar2;

  undefined1 uVar3;

  longlong *plVar4;

  char *pcVar5;

  

  plVar4 = (longlong *)FUN_1401841a0(1,0x80);

  if (plVar4 == (longlong *)0x0) {

    return 0;

  }

  *plVar4 = param_1;

  *(longlong **)(param_1 + 0x70) = plVar4;

  cVar2 = FUN_140283390(param_1);

  if (cVar2 == '\0') {

    return 0;

  }

  *(undefined2 *)((longlong)plVar4 + 10) = *(undefined2 *)(param_1 + 0x24);

  sVar1 = *(short *)(param_1 + 0x22);

  if (sVar1 == 0x10dd) {

    pcVar5 = "HHL GC Ultimate";

  }

  else if (sVar1 == 0x10df) {

    pcVar5 = "HHL ProGCC";

  }

  else if (sVar1 == 0x10e0) {

    pcVar5 = "Bonziri FireBird";

  }

  else {

    if (sVar1 != 0x10e5) goto LAB_140282564;

    pcVar5 = "Void Gaming PS4 FireBird";

  }

  FUN_1402083c0(param_1,pcVar5);

LAB_140282564:

  uVar3 = FUN_140208110(param_1,0);

  return uVar3;

}




