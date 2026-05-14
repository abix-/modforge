// Address: 0x140300490
// Ghidra name: FUN_140300490
// ============ 0x140300490 FUN_140300490 (size=116) ============


void FUN_140300490(void)



{

  char cVar1;

  longlong *plVar2;

  longlong *plVar3;

  

  cVar1 = *(char *)((longlong)*(longlong **)(DAT_1403ead08 + 8) + 0x19);

  plVar3 = *(longlong **)(DAT_1403ead08 + 8);

  while (cVar1 == '\0') {

    FUN_140074ba0(&DAT_1403ead08,&DAT_1403ead08,plVar3[2]);

    plVar2 = (longlong *)*plVar3;

    FUN_140027900(plVar3 + 4);

    FUN_1402c7088(plVar3,0x48);

    plVar3 = plVar2;

    cVar1 = *(char *)((longlong)plVar2 + 0x19);

  }

  FUN_1402c7088(DAT_1403ead08,0x48);

  return;

}




