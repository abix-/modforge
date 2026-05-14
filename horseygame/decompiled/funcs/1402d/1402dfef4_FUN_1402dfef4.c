// Address: 0x1402dfef4
// Ghidra name: FUN_1402dfef4
// ============ 0x1402dfef4 FUN_1402dfef4 (size=98) ============


undefined8 FUN_1402dfef4(longlong *param_1)



{

  char cVar1;

  longlong *plVar2;

  longlong lVar3;

  undefined1 *puVar4;

  bool bVar5;

  

  plVar2 = (longlong *)*param_1;

  cVar1 = *(char *)param_1[1];

  lVar3 = plVar2[2];

  plVar2[2] = lVar3 - 1U;

  if (((plVar2[1] == 0) || (lVar3 - 1U <= (ulonglong)plVar2[1])) && (1 < (byte)(cVar1 + 1U))) {

    plVar2 = (longlong *)*plVar2;

    if (plVar2[2] != *plVar2) {

      plVar2[2] = plVar2[2] + -1;

    }

  }

  *(undefined1 *)param_1[1] = 0;

  puVar4 = *(undefined1 **)(*param_1 + 0x10);

  bVar5 = *(undefined1 **)param_1[2] == puVar4;

  if (!bVar5) {

    puVar4 = *(undefined1 **)(*param_1 + 0x18);

    *puVar4 = 0;

  }

  return CONCAT71((int7)((ulonglong)puVar4 >> 8),bVar5);

}




