mkdir tmp;
mkdir tmp/b;
cd tmp;
echo "==== LS RESULT ====";
ls -1 a b;
echo "===================\n";
echo "=== FT_LS RESULT ==";
ft_ls -1 a b;
echo "===================";
cd .. ;
rm -rf tmp;
