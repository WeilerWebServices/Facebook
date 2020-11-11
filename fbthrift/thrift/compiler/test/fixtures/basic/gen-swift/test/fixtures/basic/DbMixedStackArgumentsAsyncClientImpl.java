/**
 * Autogenerated by Thrift
 *
 * DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
 *  @generated
 */

package test.fixtures.basic;

import com.facebook.nifty.client.RequestChannel;
import com.facebook.swift.codec.*;
import com.facebook.swift.service.*;
import com.facebook.swift.service.metadata.*;
import com.facebook.swift.transport.client.*;
import com.google.common.util.concurrent.ListenableFuture;
import java.io.*;
import java.lang.reflect.Method;
import java.util.*;
import org.apache.thrift.ProtocolId;
import reactor.core.publisher.Mono;

@SwiftGenerated
public class DbMixedStackArgumentsAsyncClientImpl extends AbstractThriftClient implements DbMixedStackArguments.Async {

    // Method Handlers
    private ThriftMethodHandler getDataByKey0MethodHandler;
    private ThriftMethodHandler getDataByKey1MethodHandler;

    // Method Exceptions
    private static final Class[] getDataByKey0Exceptions = new Class[] {
        org.apache.thrift.TException.class};
    private static final Class[] getDataByKey1Exceptions = new Class[] {
        org.apache.thrift.TException.class};

    public DbMixedStackArgumentsAsyncClientImpl(
        RequestChannel channel,
        Map<Method, ThriftMethodHandler> methods,
        Map<String, String> headers,
        Map<String, String> persistentHeaders,
        List<? extends ThriftClientEventHandler> eventHandlers) {
      super(channel, headers, persistentHeaders, eventHandlers);

      Map<String, ThriftMethodHandler> methodHandlerMap = new HashMap<>();
      methods.forEach(
          (key, value) -> {
            methodHandlerMap.put(key.getName(), value);
          });

      // Set method handlers
      getDataByKey0MethodHandler = methodHandlerMap.get("getDataByKey0");
      getDataByKey1MethodHandler = methodHandlerMap.get("getDataByKey1");
    }

    public DbMixedStackArgumentsAsyncClientImpl(
        Map<String, String> headers,
        Map<String, String> persistentHeaders,
        Mono<? extends RpcClient> rpcClient,
        ThriftServiceMetadata serviceMetadata,
        ThriftCodecManager codecManager,
        ProtocolId protocolId,
        Map<Method, ThriftMethodHandler> methods) {
      super(headers, persistentHeaders, rpcClient, serviceMetadata, codecManager, protocolId);

      Map<String, ThriftMethodHandler> methodHandlerMap = new HashMap<>();
      methods.forEach(
          (key, value) -> {
            methodHandlerMap.put(key.getName(), value);
          });

      // Set method handlers
      getDataByKey0MethodHandler = methodHandlerMap.get("getDataByKey0");
      getDataByKey1MethodHandler = methodHandlerMap.get("getDataByKey1");
    }

    @java.lang.Override
    public void close() {
        super.close();
    }


    @java.lang.Override
    public ListenableFuture<byte[]> getDataByKey0(
        String key) {
        try {
          return (ListenableFuture<byte[]>) execute(getDataByKey0MethodHandler, getDataByKey0Exceptions, key);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }

    @java.lang.Override
    public ListenableFuture<byte[]> getDataByKey1(
        String key) {
        try {
          return (ListenableFuture<byte[]>) execute(getDataByKey1MethodHandler, getDataByKey1Exceptions, key);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }


    public ListenableFuture<byte[]> getDataByKey0(
        String key,
        RpcOptions rpcOptions) {
        try {
          return (ListenableFuture<byte[]>) executeWithOptions(getDataByKey0MethodHandler, getDataByKey0Exceptions, rpcOptions, key);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }

    public ListenableFuture<byte[]> getDataByKey1(
        String key,
        RpcOptions rpcOptions) {
        try {
          return (ListenableFuture<byte[]>) executeWithOptions(getDataByKey1MethodHandler, getDataByKey1Exceptions, rpcOptions, key);
        } catch (Throwable t) {
          throw new RuntimeTException(t.getMessage(), t);
        }
    }
}