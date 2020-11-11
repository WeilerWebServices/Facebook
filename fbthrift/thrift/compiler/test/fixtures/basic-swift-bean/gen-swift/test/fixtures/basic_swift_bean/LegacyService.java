/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.basic_swift_bean;

import com.facebook.swift.codec.*;
import com.facebook.swift.codec.ThriftField.Requiredness;
import com.facebook.swift.service.*;
import com.google.common.util.concurrent.ListenableFuture;
import java.io.*;
import java.util.*;

@SwiftGenerated
@ThriftService("LegacyService")
public interface LegacyService extends java.io.Closeable {
    @ThriftService("LegacyService")
    public interface Async extends java.io.Closeable {
        @java.lang.Override void close();

        @ThriftMethod(value = "getPoints")
        ListenableFuture<Map<String, List<Integer>>> getPoints(
            @ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final Set<String> key,
            @ThriftField(value=-1, isLegacyId=true, name="legacyStuff", requiredness=Requiredness.NONE) final long legacyStuff);
    }
    @java.lang.Override void close();

    @ThriftMethod(value = "getPoints")
    Map<String, List<Integer>> getPoints(
        @ThriftField(value=1, name="key", requiredness=Requiredness.NONE) final Set<String> key,
        @ThriftField(value=-1, isLegacyId=true, name="legacyStuff", requiredness=Requiredness.NONE) final long legacyStuff) throws org.apache.thrift.TException;
}