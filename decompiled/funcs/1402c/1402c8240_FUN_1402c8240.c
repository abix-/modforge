// Address: 0x1402c8240
// Ghidra name: FUN_1402c8240
// ============ 0x1402c8240 FUN_1402c8240 (size=167) ============


void FUN_1402c8240(longlong *param_1,byte *param_2)



{

  ULONG_PTR UVar1;

  PVOID local_38;

  ULONG_PTR local_30;

  longlong *local_28;

  byte *local_20;

  PVOID local_18;

  

  UVar1 = 0x19930520;

  if ((param_2 != (byte *)0x0) && ((*param_2 & 0x10) != 0)) {

    param_2 = *(byte **)(*(longlong *)(*param_1 + -8) + 0x30);

    (*(code *)PTR__guard_dispatch_icall_140302c68)();

  }

  local_38 = (PVOID)0x0;

  if (param_2 != (byte *)0x0) {

    local_38 = RtlPcToFileHeader(param_2,&local_38);

    if (((*param_2 & 8) != 0) || (local_38 == (PVOID)0x0)) {

      UVar1 = 0x1994000;

    }

  }

  local_30 = UVar1;

  local_28 = param_1;

  local_20 = param_2;

  local_18 = local_38;

  RaiseException(0xe06d7363,1,4,&local_30);

  return;

}




