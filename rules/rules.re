foo {
    if (true == true) {}

    *xyz = "foo";

    # This points to the catalog provider FQDN
    remote("irods","") {
        *b = *xyz;
    }
}

filler {
    # Keep adding single filler line like below to trigger the error
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
    *a = 1;
}
