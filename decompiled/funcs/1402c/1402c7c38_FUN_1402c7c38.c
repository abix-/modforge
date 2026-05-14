// Address: 0x1402c7c38
// Ghidra name: FUN_1402c7c38
// ============ 0x1402c7c38 FUN_1402c7c38 (size=331) ============


void FUN_1402c7c38(undefined4 param_1)



{

  code *pcVar1;

  BOOL BVar2;

  LONG LVar3;

  PRUNTIME_FUNCTION FunctionEntry;

  undefined1 *puVar4;

  undefined8 unaff_retaddr;

  DWORD64 local_res10;

  undefined1 local_res18 [8];

  undefined1 local_res20 [8];

  undefined1 auStack_5c8 [8];

  undefined1 auStack_5c0 [232];

  undefined1 local_4d8 [152];

  undefined1 *local_440;

  DWORD64 local_3e0;

  

  puVar4 = auStack_5c8;

  BVar2 = IsProcessorFeaturePresent(0x17);

  if (BVar2 != 0) {

    pcVar1 = (code *)swi(0x29);

    (*pcVar1)(param_1);

    puVar4 = auStack_5c0;

  }

  *(undefined8 *)(puVar4 + -8) = 0x1402c7c6c;

  FUN_1402c7c2c(3);

  *(undefined8 *)(puVar4 + -8) = 0x1402c7c7d;

  FUN_1402f94c0(local_4d8,0,0x4d0);

  *(undefined8 *)(puVar4 + -8) = 0x1402c7c87;

  RtlCaptureContext(local_4d8);

  *(undefined8 *)(puVar4 + -8) = 0x1402c7ca1;

  FunctionEntry = RtlLookupFunctionEntry(local_3e0,&local_res10,(PUNWIND_HISTORY_TABLE)0x0);

  if (FunctionEntry != (PRUNTIME_FUNCTION)0x0) {

    *(undefined8 *)(puVar4 + 0x38) = 0;

    *(undefined1 **)(puVar4 + 0x30) = local_res18;

    *(undefined1 **)(puVar4 + 0x28) = local_res20;

    *(undefined1 **)(puVar4 + 0x20) = local_4d8;

    *(undefined8 *)(puVar4 + -8) = 0x1402c7ce5;

    RtlVirtualUnwind(0,local_res10,local_3e0,FunctionEntry,*(PCONTEXT *)(puVar4 + 0x20),

                     *(PVOID **)(puVar4 + 0x28),*(PDWORD64 *)(puVar4 + 0x30),

                     *(PKNONVOLATILE_CONTEXT_POINTERS *)(puVar4 + 0x38));

  }

  local_440 = &stack0x00000008;

  *(undefined8 *)(puVar4 + -8) = 0x1402c7d17;

  FUN_1402f94c0(puVar4 + 0x50,0,0x98);

  *(undefined8 *)(puVar4 + 0x60) = unaff_retaddr;

  *(undefined4 *)(puVar4 + 0x50) = 0x40000015;

  *(undefined4 *)(puVar4 + 0x54) = 1;

  *(undefined8 *)(puVar4 + -8) = 0x1402c7d39;

  BVar2 = IsDebuggerPresent();

  *(undefined1 **)(puVar4 + 0x40) = puVar4 + 0x50;

  *(undefined1 **)(puVar4 + 0x48) = local_4d8;

  *(undefined8 *)(puVar4 + -8) = 0x1402c7d56;

  SetUnhandledExceptionFilter((LPTOP_LEVEL_EXCEPTION_FILTER)0x0);

  *(undefined8 *)(puVar4 + -8) = 0x1402c7d61;

  LVar3 = UnhandledExceptionFilter((_EXCEPTION_POINTERS *)(puVar4 + 0x40));

  if ((LVar3 == 0) && (BVar2 != 1)) {

    *(undefined8 *)(puVar4 + -8) = 0x1402c7d72;

    FUN_1402c7c2c(3);

  }

  return;

}




