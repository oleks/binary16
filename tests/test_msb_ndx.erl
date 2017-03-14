-module(test_msb_ndx).
-include_lib("eqc/include/eqc.hrl").
-compile(export_all).

prop_msb_ndx() ->
    ?SETUP(fun () -> eqc_c:start(binary16),
                     fun() -> ok end
           end,
           ?FORALL(Width, choose(0, 32),
           ?FORALL(X, choose(1 bsl (Width - 1), (1 bsl Width) - 1),
            equals(Width, binary16:msb_ndx(X))))).

prop_test_examples() ->
           ?FORALL(X, int(),
            equals(X, X)).
