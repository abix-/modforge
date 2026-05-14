// Address: 0x140300990
// Ghidra name: FUN_140300990
// ============ 0x140300990 FUN_140300990 (size=116) ============


void FUN_140300990(void)



{

  char cVar1;

  longlong *plVar2;

  longlong *plVar3;

  

  cVar1 = *(char *)((longlong)*(longlong **)(DAT_1403f2fd8 + 8) + 0x19);

  plVar3 = *(longlong **)(DAT_1403f2fd8 + 8);

  while (cVar1 == '\0') {

    FUN_140074ba0(&DAT_1403f2fd8,&DAT_1403f2fd8,plVar3[2]);

    plVar2 = (longlong *)*plVar3;

    FUN_140027900(plVar3 + 4);

    FUN_1402c7088(plVar3,0x48);

    plVar3 = plVar2;

    cVar1 = *(char *)((longlong)plVar2 + 0x19);

  }

  FUN_1402c7088(DAT_1403f2fd8,0x48);

  return;

}




